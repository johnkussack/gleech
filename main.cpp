// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// OpenGL 3.0 libraries
#include <glincludes.h>
#include <AntTweakBar.h>

#include <camera/Camera.h>
#include <controls/Controls.h>
#include <scene/Scene.h>
#include <Loader.h>

using namespace glm;

Scene* scene;
Loader* loader;
Controls* controls;
Camera* cam;

double x;double y; double z;


// << BINDINGS >>

void GLFWCALL OnMousePos(int mouseX, int mouseY){
    if(!TwEventMousePosGLFW(mouseX, mouseY)){
        controls->OnMousePos(mouseX, mouseY);
    }
}

void GLFWCALL OnMouseClick(int mouseX, int mouseY){
    if(!TwEventMouseButtonGLFW(mouseX, mouseY)){
        controls->OnMouseClick(mouseX, mouseY);
    }
}

void GLFWCALL OnKeyCallback(int key, int action){

    if (!TwEventKeyGLFW(key,action)){
        controls->OnKeyCallback(key,action);
    }
}


int main(){
    GLFWvidmode mode;   // GLFW video mode


    if( !glfwInit() ){
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }
    glfwGetDesktopMode(&mode);

    //glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    //glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE,GL_TRUE);
    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);



    // Open a window and create its OpenGL context
    if( !glfwOpenWindow( 1024, 768, 0,0,0,0, 32,0, GLFW_WINDOW ) ) {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        return -1;
    }

    // Initialize GLEW
    glewExperimental=true; // Needed in core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }


    // <<GLFW SETTINGS >>
    glfwSetWindowTitle( "GLeech" );

    glfwEnable(GLFW_STICKY_KEYS );
    glfwEnable(GLFW_MOUSE_CURSOR);
    glfwEnable(GLFW_KEY_REPEAT);


    // <<OpenGL SETTINGS >>

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);    // use default light diffuse and position
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(3.0);
    glDepthFunc(GL_LESS);
    //glEnable(GL_CULL_FACE);

    // <<AntTweakBar >>
    TwWindowSize(1024, 768);

    TwBar *myBar;
    // Initialize AntTweakBar
    TwInit(TW_OPENGL, NULL);

    // Create a tweak bar
    myBar = TwNewBar("Gleech TEST");

    double speed;
    bool wire = false;


    TwDefine(" GLOBAL help='This example shows how to integrate AntTweakBar with GLFW and OpenGL.' "); // Message added to the help bar.

    // Add 'speed' to 'bar': it is a modifable (RW) variable of type TW_TYPE_DOUBLE. Its key shortcuts are [s] and [S].
    TwAddVarRW(myBar, "speed", TW_TYPE_DOUBLE, &speed,
               " label='Rot speed' min=0 max=2 step=0.01 keyIncr=s keyDecr=S help='Rotation speed (turns/second)' ");

    // Add 'wire' to 'bar': it is a modifable variable of type TW_TYPE_BOOL32 (32 bits boolean). Its key shortcut is [w].
    TwAddVarRW(myBar, "wire", TW_TYPE_BOOL32, &wire,
               " label='Wireframe mode' key=w help='Toggle wireframe display mode.' ");

    // Add 'time' to 'bar': it is a read-only (RO) variable of type TW_TYPE_DOUBLE, with 1 precision digit
    //TwAddVarRO(myBar, "x", TW_TYPE_DOUBLE, &x, " label='X' precision=1 help='Time (in seconds).' ");
    //TwAddVarRO(myBar, "y", TW_TYPE_DOUBLE, &y, " label='Y' precision=1 help='Time (in seconds).' ");
   // TwAddVarRO(myBar, "z", TW_TYPE_DOUBLE, &z, " label='Z' precision=1 help='Time (in seconds).' ");

    glfwSetMousePosCallback(OnMousePos);
    glfwSetMouseButtonCallback(OnMouseClick);
    glfwSetKeyCallback(OnKeyCallback);

    /*
    // - Directly redirect GLFW mouse position events to AntTweakBar

    // - Directly redirect GLFW mouse wheel events to AntTweakBar
    glfwSetMouseWheelCallback((GLFWmousewheelfun)TwEventMouseWheelGLFW);
    // - Directly redirect GLFW key events to AntTweakBar

    // - Directly redirect GLFW char events to AntTweakBar
    glfwSetCharCallback((GLFWcharfun)TwEventCharGLFW);*/



    // << Engine parts >>
    cam = new Camera();
    controls = new Controls(cam);

    scene = new Scene(cam);
    loader = new Loader(scene);



    do{

        glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );

        scene->render();

        x = cam->position.x;
        y = cam->position.y;
        z = cam->position.z;

        TwDraw();  // draw the tweak bar(s)

        glfwSwapBuffers();
    }
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&  glfwGetWindowParam( GLFW_OPENED ) );



    delete controls;
    delete cam;
    delete scene;
    delete loader;


    TwTerminate();
    glfwTerminate(); // End of GLFW

    return 0;

}

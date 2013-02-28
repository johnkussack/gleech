// Include the global object
#include <Globals.h>

// Include Luna (Lua) libraries
#include <lua/luna.h>
#include <lua/LunaLoader.h>

#include <camera/Camera.h>
#include <controls/Controls.h>

#include <scene/Scene.h>
#include <Loader.h>


using namespace glm;


Loader* loader;
Scene* scene;
sf::Font font;


void resizeGL( int w, int h ) {
	glViewport( 0, 0, w, h );
	//glMatrixMode( GL_PROJECTION );
	//glLoadIdentity();
	//gluPerspective( 120.0, (GLdouble)w/(GLdouble)h, 0.5, 500.0 );
	//glMatrixMode( GL_MODELVIEW );
	///TODO
}

int main(){
    
    
    Globals glb;
        
    // SFML Window generation
    sf::RenderWindow render_window( sf::VideoMode( glb.APPWIDTH, glb.APPHEIGHT), glb.APPTITLE, sf::Style::Titlebar | sf::Style::Close );
    sf::Event event;


    // GLEW initialization
    glewExperimental=true; // Needed in core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW (Old hardware?)\n");
        return -1;
    }


    if (!font.loadFromFile("/root/workspace/gleech/resources/MonospaceTypewriter.ttf")){
        cout<<"Could not load default font!"<<endl;
        exit(1);

    }

    scene = new Scene(&glb);
    loader = new Loader(&glb, scene);

       
    // LUA INIT
    lua_State* L = lua_open();
    luaL_openlibs(L);

    Luna<LunaLoader>::Register(L);
    lua_pushlightuserdata(L, (void*)loader);
    lua_setglobal(L,"loader");

    if(luaL_dofile(L,"/root/workspace/gleech/resources/init.lua")){
        cout<<"Error during load of the LUA core: "<<lua_tostring(L,-1)<<endl;
    }

    // LUA INIT END

    sf::Text text(glb.GUITITLE,font,25);
    text.setColor(sf::Color(255, 255, 255));
    text.setPosition(10, 10);

    // GL SETTINGS
    glEnable(GL_DEPTH_TEST);

    while( render_window.isOpen() ) {
        while( render_window.pollEvent( event ) ) {
            if( event.type == sf::Event::Closed ) {
                    render_window.close();
            }
            else {
                if( event.type==sf::Event::Resized ){
                    resizeGL( event.size.width, event.size.height );
                }

                if (event.type==sf::Event::KeyReleased && event.key.code == sf::Keyboard::F12){
                    sf::Image Screen =render_window.capture();
                    Screen.saveToFile("/root/screenshot.jpg");
                    cout<<"SNAPSHOT"<<endl;
                 }
            }
        }

        glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );

        scene->render();

        render_window.pushGLStates();
            render_window.draw(text);
        render_window.popGLStates();
        
        render_window.display();

    }


    // Cleaning
    lua_close(L);

    delete scene;
    delete loader;
    
    
    // Let global objects delete themselves

    return 0;

}

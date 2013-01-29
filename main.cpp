// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// OpenGL 3.0 libraries
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <shader.h>


using namespace glm;

unsigned int vaoID[1]; // Our Vertex Array Object
unsigned int vboID[2]; // Our Vertex Buffer Object
int TRIANGLE_COUNT = 0;

Shader* shader;

void createSquare(void) {
    float* vertices = new float[18];  // Vertices for our square
    float* colors = new float[18];  // Vertices for our square

    vertices[0] = -0.5; vertices[1] = -0.5; vertices[2] = 0.0; // Bottom left corner
    colors[0] = 1.0; colors[1] = 1.0; colors[2] = 1.0; // Bottom left corner

    vertices[3] = -0.5; vertices[4] = 0.5; vertices[5] = 0.0; // Top left corner
    colors[3] = 1.0; colors[4] = 0.0; colors[5] = 0.0; // Top left corner

    vertices[6] = 0.5; vertices[7] = 0.5; vertices[8] = 0.0; // Top Right corner
    colors[6] = 0.0; colors[7] = 1.0; colors[8] = 0.0; // Top Right corner

    vertices[9] = 0.5; vertices[10] = -0.5; vertices[11] = 0.0; // Bottom right corner
    colors[9] = 0.0; colors[10] = 0.0; colors[11] = 1.0; // Bottom right corner

    vertices[12] = -0.5; vertices[13] = -0.5; vertices[14] = 0.0; // Bottom left corner
    colors[12] = 1.0; colors[13] = 1.0; colors[14] = 1.0; // Bottom left corner

    vertices[15] = 0.5; vertices[16] = 0.5; vertices[17] = 0.0; // Top Right corner
    colors[15] = 0.0; colors[16] = 1.0; colors[17] = 0.0; // Top Right corner

    glGenVertexArrays(1, &vaoID[0]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it

    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object

    //VBO[0] Vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object

    //VBO[1] Colors
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array


    glBindVertexArray(0); // Disable our Vertex Buffer Object

    TRIANGLE_COUNT = 3; // 3 index * 1 triangles = 1 triangle

    delete [] colors;
    delete [] vertices; // Delete our vertices from memory

}

void createCube(){
    GLfloat vertices[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};


    GLfloat colors [] = {
    0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
};

    glGenVertexArrays(1, &vaoID[0]); // Create our Vertex Array Object
    glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object so we can use it

    glGenBuffers(2, vboID); // Generate our Vertex Buffer Object

    //VBO[0] Vertices
    glBindBuffer(GL_ARRAY_BUFFER, vboID[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Disable our Vertex Array Object

    //VBO[1] Colors
    glBindBuffer(GL_ARRAY_BUFFER, vboID[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array


    glBindVertexArray(0); // Disable our Vertex Buffer Object

    TRIANGLE_COUNT = 12*3; // 3 index * 12 triangles = 6 squares = 1 cube
}

int main(){

    if( !glfwInit() ){
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

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

        glfwSetWindowTitle( "GLeech" );

    // Ensure we can capture the escape key being pressed below
        glfwEnable( GLFW_STICKY_KEYS );

    // Enable shaders (vertices & fragments)
        shader = new Shader("/root/voxel/opengl3/shader.vert", "/root/voxel/opengl3/shader.frag");

    //createSquare(); // DO VAO startup
        createCube();

    // Matrices

        // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
        glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        // Camera matrix
        glm::mat4 View       = glm::lookAt(
            glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
            glm::vec3(0,0,0), // and looks at the origin
            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
        );

        // Model matrix : an identity matrix (model will be at the origin)
        glm::mat4 Model      = glm::mat4(1.0f);  // Changes for each model !
        // Our ModelViewProjection : multiplication of our 3 matrices
        glm::mat4 MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around


        // Enable depth test
        //glEnable(GL_DEPTH_TEST);
        // Accept fragment if it closer to the camera than the former one
        //glDepthFunc(GL_LESS);

    do{

        glViewport(0, 0, 1024, 768); // Set the viewport size to fill the window
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // Clear required buffers

        shader->bind(); // Bind our shader

        // Get a handle for our "MVP" uniform.
        // Only at initialisation time.

        GLuint MatrixID = glGetUniformLocation(shader->id(), "MVP");

        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        // For each model you render, since the MVP will be different (at least the M part)
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // DRAW VBAO contents
        glBindVertexArray(vaoID[0]); // Bind our Vertex Array Object
        glDrawArrays(GL_TRIANGLES, 0, TRIANGLE_COUNT); // Draw our square
        glBindVertexArray(0); // Unbind our Vertex Array Object
        // DRAW END


        shader->unbind(); // Unbind our shader

        // Swap buffers
        glfwSwapBuffers();

    } // Check if the ESC key was pressed or the window was closed

    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&  glfwGetWindowParam( GLFW_OPENED ) );


    delete shader;

    glfwTerminate(); // End of GLFW

    return 0;

}



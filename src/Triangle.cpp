#include "Triangle.h"

Triangle::Triangle(){
    //ctor
    vaoOn = false;
}

Triangle::~Triangle(){

    if (vaoOn){
        glDeleteBuffers(2, vbo);
        glDeleteBuffers(1, vao);

    }

}

void Triangle::Create(Shader* _shader){

    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
    };

    GLfloat addons [] = {
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f
    }; //PURE RED


    glGenVertexArrays(1, &vao[0]); // Create our Vertex Array Object
    glBindVertexArray(vao[0]); // Bind our Vertex Array Object so we can use it

    glGenBuffers(2, vbo); // Generate our Vertex Buffer Object

    //VBO[0] Vertices
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Enable the second vertex attribute array
    //VBO[1] Colors
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, sizeof(addons), addons, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array


    glBindVertexArray(0); // Disable our Vertex Buffer Object

    TRIANGLE_INDEX_COUNT = 1*3; // 3 index * 1 triangle = 1 triangle

    vaoOn = true; // We got STUFF on VAO now
    shader = _shader; // Store the shader to use with this
}


void Triangle::Render(GLuint MatrixID, GLfloat* MVP){
    shader->bind(); // Bind our shader

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, MVP);

     // DRAW VBAO contents
    glBindVertexArray(vao[0]); // Bind our Vertex Array Object
    glDrawArrays(GL_TRIANGLES, 0, TRIANGLE_INDEX_COUNT); // Draw our square
    glBindVertexArray(0); // Unbind our Vertex Array Object
    // DRAW END

    shader->unbind(); // unbind


}

#include "Scene.h"

#include <primitives/Cube.h>
#include <primitives/Plane.h>


Scene::Scene(){
    shader = new Shader("/root/voxel/opengl3/shader.vert", "/root/voxel/opengl3/shader.frag");
    textureShader = new Shader("/root/voxel/opengl3/textureshader.vert", "/root/voxel/opengl3/textureshader.frag");

    textMan = new TextureManager(textureShader);
    textMan->loadTGATexture("/root/voxel/opengl3/uvtemplate.tga");

    cam = new CameraControls();

}

Scene::~Scene(){

    glDeleteBuffers(2, vboSolid);
    glDeleteBuffers(2, vboText);

    glDeleteBuffers(1, &vaoSolid);
    glDeleteBuffers(1, &vaoText);

    // Free shaders
    delete shader;
    delete textureShader;
    delete textMan;
    delete cam;

}




void Scene::Setup(){
    //TODO: DO NORMALS?

    // TESTING
    Cube cube;
    Plane p;

    primitives.push_back(p);

    //primitivesText.push_back(cube);
    for(int a = 0;a<16;a++){
        primitives.push_back(cube);
        //primitivesText.push_back(cube);
    }
    // TESTING

    std::vector<GLfloat> vertices;
    std::vector<GLfloat> colors;

    std::vector<GLfloat> texturesUV;

    ///SOLID VAO & VBOS
    glGenVertexArrays(1, &vaoSolid); // Create our Vertex Array Object
    glBindVertexArray(vaoSolid); // Bind our Vertex Array Object so we can use it
    glGenBuffers(2, &vboSolid[0]); // Generate our Vertex Buffer Object

    int acumulator = 0;
    for(unsigned int i = 0;i<primitives.size();i++){

        for(int j = 0;j<primitives[i].verticesCount;j++){
            vertices.push_back(primitives[i].pVertices[j]);
        }

        for(int j = 0;j<primitives[i].colorsCount;j++){
            colors.push_back(primitives[i].pColors[j]);
        }

        primitives[i].pSceneOffset = acumulator; acumulator+=primitives[i].TRIANGLE_INDEX_COUNT;
    }

    // VBOS solid
    glBindBuffer(GL_ARRAY_BUFFER, vboSolid[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat),&vertices[0], GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Enable the second vertex attribute array

    glBindBuffer(GL_ARRAY_BUFFER, vboSolid[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, colors.size()*sizeof(GLfloat),&colors[0], GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array

    glBindVertexArray(0); // Bind our Vertex Array Object so we can use it

    ///TEXTURING

    glGenVertexArrays(1, &vaoText); // Create our Vertex Array Object
    glBindVertexArray(vaoText); // Bind our Vertex Array Object so we can use it
    glGenBuffers(2, &vboText[0]); // Generate our Vertex Buffer Object

    acumulator = 0;
    vertices.clear();

    for(unsigned int i = 0;i<primitivesText.size();i++){

        for(int j = 0;j<primitivesText[i].verticesCount;j++){
            vertices.push_back(primitivesText[i].pVertices[j]);
        }

        for(int j = 0;j<primitivesText[i].texturesUVCount;j++){
            texturesUV.push_back(primitivesText[i].pTexturesUV[j]);
        }

        primitivesText[i].pSceneOffset = acumulator; acumulator+=primitivesText[i].TRIANGLE_INDEX_COUNT;
    }

    // VBOS solid
    glBindBuffer(GL_ARRAY_BUFFER, vboText[0]); // Bind our Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat),&vertices[0], GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(0); // Enable the second vertex attribute array

    glBindBuffer(GL_ARRAY_BUFFER, vboText[1]); // Bind our second Vertex Buffer Object
    glBufferData(GL_ARRAY_BUFFER, texturesUV.size()*sizeof(GLfloat),&texturesUV[0], GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
    glVertexAttribPointer((GLuint)1, 2, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer
    glEnableVertexAttribArray(1); // Enable the second vertex attribute array
    glBindVertexArray(0); // Bind our Vertex Array Object so we can use it

}

void Scene::RenderTest(){

  shader->bind(); // Bind our shader

        // Get a handle for our "MVP" uniform.
        // Only at initialisation time.

        // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
        glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        // Camera matrix
        glm::mat4 View = glm::lookAt(
            glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
            glm::vec3(0,0,0), // and looks at the origin
            glm::vec3(0,1,0) // Head is up (set to 0,-1,0 to look upside-down)
        );

        // Model matrix : an identity matrix (model will be at the origin)
        glm::mat4 Model = glm::mat4(1.0f); // Changes for each model !
        // Our ModelViewProjection : multiplication of our 3 matrices
        glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
        GLuint MatrixID = glGetUniformLocation(shader->id(), "MVP");

        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        // For each model you render, since the MVP will be different (at least the M part)
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // DRAW VBAO contents
        glBindVertexArray(vaoSolid); // Bind our Vertex Array Object
        glDrawArrays(GL_TRIANGLES, 0, 12*3); // Draw our square
        glBindVertexArray(0); // Unbind our Vertex Array Object
        // DRAW END


        shader->unbind(); // Unbind our shader
}


void Scene::Render(){

    glm::mat4 ModelMatrix;
    glm::mat4 origin = glm::mat4(1.0); //ORIGIN
    glm::mat4 MVP;

    // Process camera inputs (MOVEMENT)
    cam->processInputs();

    ///RENDER THE SCENE

    shader->bind(); // Bind our shader

        GLuint MatrixID = glGetUniformLocation(shader->id(), "MVP");
        glBindVertexArray(vaoSolid); // Bind our Vertex Array Object

            for(unsigned int i=0;i<primitives.size();i++){

                ModelMatrix = glm::translate(origin, glm::vec3(2*i, 0, -2)); // x, y, z position ?
                MVP = cam->ProjectionMatrix * cam->ViewMatrix * ModelMatrix;
                glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
                glDrawArrays(GL_TRIANGLES, primitives[i].pSceneOffset, primitives[i].TRIANGLE_INDEX_COUNT); // Draw our square
            }

        glBindVertexArray(0); // Unbind our Vertex Array Object
        // DRAW END

    shader->unbind(); // unbind


    ///RENDER THE SCENE (TEXTURES)


    textureShader->bind();

        MatrixID = glGetUniformLocation(textureShader->id(), "MVP");
        glBindVertexArray(vaoText); // Bind our Vertex Array Object

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, textMan->getTexture(0));
            glUniform1i(textMan->getTextureId(0), 0);


            for(unsigned int i=0;i<primitivesText.size();i++){
                ModelMatrix = glm::translate(origin, glm::vec3(2*i, 0, 0)); // x, y, z position ?
                MVP = cam->ProjectionMatrix * cam->ViewMatrix * ModelMatrix;
                glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
                glDrawArrays(GL_TRIANGLES, primitivesText[i].pSceneOffset, primitivesText[i].TRIANGLE_INDEX_COUNT); // Draw our square

            }

        glBindVertexArray(0);



    textureShader->unbind();


}

#include <Loader.h>

Loader::Loader(Scene* _scene){

    /**** GENERATE TEXTURES ****/

    shader = new Shader("/root/voxel/opengl3/shader.vert", "/root/voxel/opengl3/shader.frag");
    shaderTextures = new Shader("/root/voxel/opengl3/textureshader.vert", "/root/voxel/opengl3/textureshader.frag");

    textMan = new TextureManager(shaderTextures);
    textMan->loadTexture2D("/root/voxel/opengl3/texture.jpg",true);
    textMan->loadTexture2D("/root/voxel/opengl3/building.jpg",false);
    textMan->loadTexture2D("/root/voxel/opengl3/skybox.jpg", true);

    soundM = new SoundManager();
    soundM->open("/root/voxel/opengl3/alternative.ogg");


    /**** CREATE PRIMITIVES TO USE ****/

    primitiveStore.push_back(new Triangle());
    primitiveStore.push_back(new Plane());
    primitiveStore.push_back(new Cube());
    primitiveStore.push_back(new Skybox());



    /**** JOIN PRIMITIVES VALUES ****/

    std::vector<GLfloat> vertices;
    std::vector<GLfloat> colors;
    std::vector<GLfloat> texturesUV;
    std::vector<GLfloat> normals;
    int verticesAcumulator = 0;

    for(unsigned int i = 0;i<primitiveStore.size();i++){

        vertices.insert(vertices.end(), primitiveStore[i]->getVertices()->begin(), primitiveStore[i]->getVertices()->end());
        colors.insert(colors.end(), primitiveStore[i]->getColors()->begin(), primitiveStore[i]->getColors()->end());
        texturesUV.insert(texturesUV.end(), primitiveStore[i]->getTexturesUv()->begin(), primitiveStore[i]->getTexturesUv()->end());

        // Store the vertex offsets, to draw array ranges later
        primitiveStore[i]->sceneOffset = verticesAcumulator;
        verticesAcumulator+=primitiveStore[i]->getHumanVertexCount();

    }


    /**** CREATE VAO & VBO ****/



    /**  Generate VBO for solid primitives (vertex & colors) **/


    glGenBuffers(3, &sceneVbo[0]);

    glBindBuffer(GL_ARRAY_BUFFER, sceneVbo[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat),&vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, sceneVbo[1]);
    glBufferData(GL_ARRAY_BUFFER, colors.size()*sizeof(GLfloat),&colors[0], GL_STATIC_DRAW);


    glGenBuffers(3, &sceneVboTextured[0]);
    glBindBuffer(GL_ARRAY_BUFFER, sceneVboTextured[0]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat),&vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, sceneVboTextured[1]);
    glBufferData(GL_ARRAY_BUFFER, texturesUV.size()*sizeof(GLfloat),&texturesUV[0], GL_STATIC_DRAW);


        /**** Pass info to the scene & setup ****/

    _scene->setup(sceneVao,sceneVbo, sceneVaoTextured, sceneVboTextured, shader, shaderTextures,soundM);


    /**** TEST STUFF ADDING HERE ****/

    SceneItem* testItem = new SceneItem();
        testItem->SetPrimitive(primitiveStore[1]); //plane
        testItem->SetScale(90,1,90);
        testItem->SetTranslation(0,0.5,0);
        testItem->SetTexture(textMan->getTexture(0),textMan->getTextureId(0));

    _scene->pushItem(testItem);


    //BUILDINGS
    testItem = new SceneItem();
        testItem->SetPrimitive(primitiveStore[2]); // cube
        testItem->SetTranslation(-1.0f,0.5f,0);
        testItem->SetScale(10,15,10);
        testItem->SetTexture(textMan->getTexture(1),textMan->getTextureId(1));
    _scene->pushItem(testItem);

    testItem = new SceneItem();
        testItem->SetPrimitive(primitiveStore[2]); // cube
        testItem->SetTranslation(-1.0f,0.5f,-3.0);
        testItem->SetScale(10,15,10);
        testItem->SetTexture(textMan->getTexture(1),textMan->getTextureId(1));
    _scene->pushItem(testItem);

    testItem = new SceneItem();
        testItem->SetPrimitive(primitiveStore[2]); // cube
        testItem->SetTranslation(1.0f,0.5f,-3.0);
        testItem->SetScale(10,15,10);
        testItem->SetTexture(textMan->getTexture(1),textMan->getTextureId(1));
    _scene->pushItem(testItem);

    //SKYBOX


    testItem = new SceneItem();
        testItem->SetPrimitive(primitiveStore[3]); // skybox
        testItem->SetTexture(textMan->getTexture(2),textMan->getTextureId(2));
        testItem->SetScale(100,100,100);
    _scene->pushItem(testItem);



}

Loader::~Loader(){

    // Scene deletes its own sceneitems, not us!

    for(unsigned int i = 0;i<primitiveStore.size();i++){
        delete primitiveStore[i];
    }

    glDeleteBuffers(3, sceneVbo);
    glDeleteBuffers(3, sceneVboTextured);

    glDeleteVertexArrays(1, &sceneVao);
    glDeleteVertexArrays(1, &sceneVaoTextured);



    delete soundM;
    delete textMan;
    delete shader;
    delete shaderTextures;
}

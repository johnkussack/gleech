
#include <Loader.h>

Loader::Loader(Globals* _glb, Scene* _scene){
    glb = _glb;
    scene = _scene;

}


void Loader::InitShaders(string vertexPath, string fragmentPath,string textureVertexPath, string textureFragmentPath){
    glb->solidShader = new Shader(vertexPath.c_str(), fragmentPath.c_str());
    glb->textureShader = new Shader(textureVertexPath.c_str(), textureFragmentPath.c_str());
    glb->textMan = new TextureManager();
   
}

void Loader::InitPrimitives(){

    primitiveStore.push_back(new Triangle());
    primitiveStore.push_back(new Plane());
    primitiveStore.push_back(new Cube());
    primitiveStore.push_back(new Skybox());

    /**** JOIN PRIMITIVES VALUES ****/

    vector<GLfloat> vertices;
    vector<GLfloat> colors;
    vector<GLfloat> normals;
    vector<GLfloat> texturesUV;

    /**** CREATE PRIMITIVES TO USE ****/

    int verticesAcumulator = 0;

    for(unsigned int i = 0;i<primitiveStore.size();i++){

        unsigned int totalVertices = primitiveStore.at(i)->getVerticesCount();

        for(unsigned int j = 0;j<totalVertices;j++){

            ModelVertex* v = primitiveStore.at(i)->getVertex(j);

            vertices.push_back(v->coords.x);
            vertices.push_back(v->coords.y);
            vertices.push_back(v->coords.z);

            colors.push_back(v->color.x);
            colors.push_back(v->color.y);
            colors.push_back(v->color.z);

            normals.push_back(v->normal.x);
            normals.push_back(v->normal.y);
            normals.push_back(v->normal.z);

            texturesUV.push_back(v->uvCoords.x);
            texturesUV.push_back(v->uvCoords.y);

        }

        verticesAcumulator+=primitiveStore[i]->getVerticesCount();

    }

    cout<<"VAO CHECK. Vertices count: "<<vertices.size()<<endl;
    cout<<"VAO CHECK. Color count: "<<colors.size()<<endl;
    cout<<"VAO CHECK. Normal count: "<<normals.size()<<endl;
    cout<<"VAO CHECK. UV count: "<<texturesUV.size()<<endl;

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


    glBindBuffer(GL_ARRAY_BUFFER,0);
    
    /**** Pass info to the scene & setup ****/

    scene->setup(sceneVbo, sceneVboTextured);


}

void Loader::LoadTexture(string path, bool skybox){
    glb->textMan->loadTexture2D(path.c_str(),skybox);
}

void Loader::AddPrimitive(int index, int textureIndex, glm::vec3 scale,glm::vec3 translation){
    SceneItem* testItem = new SceneItem();
        testItem->SetPrimitive(primitiveStore[index]);
        testItem->SetScale(scale.x,scale.y,scale.z);
        testItem->SetTranslation(translation.x,translation.y,translation.z);
        if(textureIndex>=0){
            testItem->SetTexture(glb->textMan->getTexture(textureIndex));
        }
    scene->pushItem(testItem);
}

void Loader::AddMxoMga(string path, int textureIndex, glm::vec3 translation){
    MxoMga mga(path);

    if(mga.Parse()){
        IndexedModel *temp = mga.getModel();

        temp->setTranslation(translation);
        for(int i = 0; i< temp->getModelMeshCount();i++){
            temp->setTexture(i,glb->textMan->getTexture(textureIndex));
        }


        scene->pushModel(temp);
    }else{
        cout<<"Could not load MXO MGA: "<<path<<endl;
    }

}

void Loader::AddMxoProp(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation){

    MxoProp prop(path);
    if(prop.Parse()){

        IndexedModel *temp = prop.getModel();
        temp->setScale(scale);
        temp->setRotation(rotation);
        temp->setTranslation(translation);
        
        for(int i = 0; i< temp->getModelMeshCount();i++){
            temp->setTexture(i,glb->textMan->getTexture(textureIndex));
        }

        scene->pushModel(temp);
    }else{
        cout<<"Could not load MXO Prop: "<<path<<endl;
    }

}

void Loader::AddMxoEprf(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation){

    MxoEprf eprf(path);
    if(eprf.Parse()){
        
        IndexedModel* temp = eprf.getModel();
        temp->setScale(scale);
        temp->setRotation(rotation);
        temp->setTranslation(translation);
        
        for(int i = 0; i< temp->getModelMeshCount();i++){
            temp->setTexture(i,glb->textMan->getTexture(textureIndex));
        }

        scene->pushModel(temp);
        
    }else{
        cout<<"Could not load MXO Eprf: "<<path<<endl;
    }
    
}

void Loader::AddMxoIprf(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation){

    MxoIprf iprf(path);
    if(iprf.Parse()){
        
        IndexedModel* temp = iprf.getModel();
        temp->setScale(scale);
        temp->setRotation(rotation);
        temp->setTranslation(translation);
        
        for(int i = 0; i< temp->getModelMeshCount();i++){
            temp->setTexture(i,glb->textMan->getTexture(textureIndex));
        }

        scene->pushModel(temp);
        
    }else{
        cout<<"Could not load MXO Iprf: "<<path<<endl;
    }
    
}


Loader::~Loader(){

    // Scene deletes its own sceneitems, not us!

    for(unsigned int i = 0;i<primitiveStore.size();i++){
        delete primitiveStore[i];
    }
    primitiveStore.clear();

    glDeleteBuffers(3, sceneVbo);
    glDeleteBuffers(3, sceneVboTextured);


}

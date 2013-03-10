
#include <Loader.h>

Loader::Loader(Globals* _glb, Scene* _scene){
    glb = _glb;
    scene = _scene;
}

void Loader::initShaders(string vertexPath, string fragmentPath,string textureVertexPath, string textureFragmentPath){
    glb->solidShader = new Shader(vertexPath.c_str(), fragmentPath.c_str());
    glb->textureShader = new Shader(textureVertexPath.c_str(), textureFragmentPath.c_str());
    glb->textMan = new TextureManager();
   
}

void Loader::loadTexture(string path, bool skybox){
    glb->textMan->loadTexture2D(path.c_str(),skybox);
}

int Loader::modelIndex(string path){
    return (glb->modelDb->isKnownModel(path));
}

void Loader::addMxoMga(string path, int textureIndex, glm::vec3 translation){
    int index = modelIndex(path);
    
    IndexedModel* m;
    SceneItem* si;
    
    if(index==-1){
    
        MxoMga mga(path);

        if(mga.Parse()){
            m = mga.getModel();
            glb->modelDb->addModel(m,path);
        }else{
            cout<<"Could not load MXO MGA: "<<path<<endl;
            return;
        }
    }else{
        m = glb->modelDb->getModel(index);
        
    }
    
    si = new SceneItem();
    si->setModel(m);
    addItemToScene(si,textureIndex,glm::vec3(1.0f),glm::vec3(0.0f),translation);

}

void Loader::addMxoProp(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation){
    int index = modelIndex(path);
    
    IndexedModel* m;
    SceneItem* si;
    
    if(index==-1){
    
        MxoProp prop(path);
        if(prop.Parse()){
            m = prop.getModel();
            glb->modelDb->addModel(m,path);
        }else{
            cout<<"Could not load MXO Prop: "<<path<<endl;
            return;
        }
    }else{
        m = glb->modelDb->getModel(index);  
    }
    
    si = new SceneItem();
    si->setModel(m);
    addItemToScene(si,textureIndex,scale,rotation,translation);

}

void Loader::addMxoEprf(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation){
    int index = modelIndex(path);
    
    IndexedModel* m;
    SceneItem* si;
    
    if(index==-1){
        MxoEprf eprf(path);
        if(eprf.Parse()){

           m = eprf.getModel();
           glb->modelDb->addModel(m,path);

        }else{
            cout<<"Could not load MXO Eprf: "<<path<<endl;
            return;
        }
    }else{
        m = glb->modelDb->getModel(index);  
    }
    
    si = new SceneItem();
    si->setModel(m);
    addItemToScene(si,textureIndex,scale,rotation,translation);
    
}

void Loader::addMxoIprf(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation){
  int index = modelIndex(path);
    
    IndexedModel* m;
    SceneItem* si;
    
    if(index==-1){
        MxoIprf iprf(path);
        if(iprf.Parse()){

           m = iprf.getModel();
           glb->modelDb->addModel(m,path);

        }else{
            cout<<"Could not load MXO Iprf: "<<path<<endl;
            return;
        }
    }else{
        m = glb->modelDb->getModel(index);  
    }
    
    si = new SceneItem();
    si->setModel(m);
    addItemToScene(si,textureIndex,scale,rotation,translation);
    
}

void Loader::addItemToScene(SceneItem* item, int textureIndex,glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation){
    item->setScale(scale);
    item->setRotation(rotation);
    item->setTranslation(translation);
    
    IndexedModel* m = item->getModel();
    
    for(int i = 0; i< m->getModelMeshCount();i++){
        m->setTexture(i,glb->textMan->getTexture(textureIndex));
    }
    
    scene->pushItem(item);
}
    


Loader::~Loader(){
    // Scene deletes its own sceneitems, not us!
}

#include <scene/SceneItem.h>

SceneItem::SceneItem(){
    scale = glm::vec3(1.0f);
    rotation = glm::vec3(0.0f);
    translation = glm::vec3(0.0f);
    modelMatrix = glm::mat4(1.0f);
}

SceneItem::~SceneItem(){
    //dtor
}

void SceneItem::setModel(IndexedModel* m){
    model = m;
}

IndexedModel* SceneItem::getModel(){
    return model;
}

void SceneItem::setScale(glm::vec3 _scale){
    scale.x = _scale.x;
    scale.y = _scale.y;
    scale.z = _scale.z;
    processModelMatrix();
}

void SceneItem::setRotation(glm::vec3 _rotation){
    rotation.x = _rotation.x;
    rotation.y = _rotation.y;
    rotation.z = _rotation.z;
    processModelMatrix();
}

void SceneItem::setTranslation(glm::vec3 _translation){
    translation.x = _translation.x;
    translation.y = _translation.y;
    translation.z = _translation.z;
    processModelMatrix();
}

void SceneItem::processModelMatrix(){
    
    glm::mat4 trans = glm::translate(glm::mat4(1.0f), translation);
    glm::mat4 transC = glm::translate(glm::mat4(1.0f), model->getCenter());
    glm::mat4 m(1.0f);
    
    m = glm::rotate(m, rotation.x , glm::vec3(1.f, 0.f, 0.f));
    m = glm::rotate(m, rotation.y, glm::vec3(0, 1, 0));
    m = glm::rotate(m, rotation.z, glm::vec3(0.f, 0.f, 1.f));
    
   if(!model->zeroCentered()){
        if(rotation.y!=0 || rotation.z!=0 || rotation.x!=0){
            m = m*transC;
            cout<<"Displacing MODEL not zerocentered"<<endl;
            trans = glm::translate(trans,-model->getCenter());
        }
    }
    
    glm::mat4 final = trans*m;
    
    modelMatrix = final;

}

glm::mat4 SceneItem::getModelMatrix(){
    return modelMatrix;
}

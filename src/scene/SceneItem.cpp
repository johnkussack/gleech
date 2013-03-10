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
    glm::mat4 m(1.0f);
    
    m = glm::translate(m,translation);
    
    m = glm::scale(m,scale);
    
    m = glm::rotate(m, rotation.x *-1.0f, glm::vec3(1.f, 0.f, 0.f));
    m = glm::rotate(m, rotation.y, glm::vec3(0.f, 1.f, 0.f));
    m = glm::rotate(m, rotation.z, glm::vec3(0.f, 0.f, 1.f));
        
    
    modelMatrix = m;
}

glm::mat4 SceneItem::getModelMatrix(){
    return modelMatrix;
}

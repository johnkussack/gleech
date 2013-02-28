#include <scene/SceneItem.h>

SceneItem::SceneItem(){
    texture = 0;
    scale[0] = 1; scale[1] = 1; scale[2] = 1;
    rotation[0] = 0; rotation[1] = 0; rotation[2] = 0; rotation[3] = 1;
    translation[0] = 0;translation[1] = 0;translation[2] = 0;
    prim = 0;
    ModelMatrix = glm::mat4(1.0f);

}

SceneItem::~SceneItem(){
    //dtor
}

void SceneItem::SetPrimitive(Primitive* _prim){
    prim = _prim;
}

void SceneItem::SetScale(float a,float b, float c){
    scale[0] = (GLfloat)a;
    scale[1] = (GLfloat)b;
    scale[2] = (GLfloat)c;
    processModelMatrix();
}

void SceneItem::SetRotation(float a,float b, float c,float d){
    rotation[0] = (GLfloat)a;
    rotation[1] = (GLfloat)b;
    rotation[2] = (GLfloat)c;
    rotation[3] = (GLfloat)d;
    processModelMatrix();
}

void SceneItem::SetTranslation(float a,float b, float c){
    translation[0] = (GLfloat)a;
    translation[1] = (GLfloat)b;
    translation[2] = (GLfloat)c;
    processModelMatrix();
}

void SceneItem::SetTexture(GLuint _texture){
    texture = _texture;
}

void SceneItem::processModelMatrix(){
    ModelMatrix = glm::mat4(1.0f);
    ModelMatrix = glm::scale(ModelMatrix,glm::vec3(scale[0],scale[1],scale[2]));
    // TODO: ROTATE
    ModelMatrix = glm::translate(ModelMatrix,glm::vec3(translation[0],translation[1],translation[2]));
}

glm::mat4 SceneItem::GetModelMatrix(){
    return ModelMatrix;
}

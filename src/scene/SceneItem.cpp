#include <scene/SceneItem.h>

SceneItem::SceneItem()
{
    texture = 0;
    textureId = 0;
    scale[0] = 1; scale[1] = 1; scale[2] = 1;
    rotation[0] = 0; rotation[1] = 0; rotation[2] = 0; rotation[3] = 1;
    prim = 0;

}

SceneItem::~SceneItem()
{
    //dtor
}

void SceneItem::SetPrimitive(Primitive* _prim){
    prim = _prim;
}

void SceneItem::SetScale(float a,float b, float c){
    scale[0] = (GLfloat)a;
    scale[1] = (GLfloat)b;
    scale[2] = (GLfloat)c;
}

void SceneItem::SetRotation(float a,float b, float c,float d){
    rotation[0] = (GLfloat)a;
    rotation[1] = (GLfloat)b;
    rotation[2] = (GLfloat)c;
    rotation[3] = (GLfloat)d;

}

void SceneItem::SetTranslation(float a,float b, float c){
    translation[0] = (GLfloat)a;
    translation[1] = (GLfloat)b;
    translation[2] = (GLfloat)c;
}

void SceneItem::SetTexture(GLuint _texture, GLuint _textureId){
    texture = _texture;
    textureId = _textureId;
}

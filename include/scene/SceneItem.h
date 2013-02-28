#ifndef SCENEITEM_H
#define SCENEITEM_H

#include <glincludes.h>
#include <primitives/Primitive.h>

class SceneItem
{
    private:
        Primitive* prim;
        GLfloat scale[3];
        GLfloat rotation[4];
        GLfloat translation[3];

        GLuint texture;

        glm::mat4 ModelMatrix;

        void processModelMatrix();


    public:
        SceneItem();
        virtual ~SceneItem();

        GLfloat getTranslation(int index){ return translation[index]; }
        GLfloat getScale(int index){ return translation[index]; }
        int getOffset() {return prim->sceneOffset; }
        int getVerticesCount(){return prim->getVerticesCount();}
        int getTexture() {return texture;}

        void SetPrimitive(Primitive* _prim);
        void SetScale(float a,float b, float c);
        void SetRotation(float a,float b, float c,float d);
        void SetTranslation(float a,float b, float c);
        void SetTexture(GLuint _texture);

        glm::mat4 GetModelMatrix();


};

#endif // SCENEITEM_H

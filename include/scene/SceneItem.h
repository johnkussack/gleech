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
        GLuint textureId;

        glm::mat4 ModelMatrix;

        void processModelMatrix();


    public:
        SceneItem();
        virtual ~SceneItem();

        GLfloat getTranslation(int index){ return translation[index]; }
        GLfloat getScale(int index){ return translation[index]; }
        int getOffset() {return prim->sceneOffset; }
        int getVerticesCount(){return prim->getHumanVertexCount();}
        int getTexture() {return texture;}
        int getTextureId() {return textureId;}


        void SetPrimitive(Primitive* _prim);
        void SetScale(float a,float b, float c);
        void SetRotation(float a,float b, float c,float d);
        void SetTranslation(float a,float b, float c);
        void SetTexture(GLuint _texture, GLuint _textureId);

        glm::mat4 GetModelMatrix();


};

#endif // SCENEITEM_H

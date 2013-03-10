#ifndef SCENEITEM_H
#define SCENEITEM_H

#include <glincludes.h>
#include <primitives/IndexedModel.h>

class SceneItem{
    
    private:
        IndexedModel* model;
        glm::vec3 scale;
        glm::vec3 rotation;
        glm::vec3 translation;

        glm::mat4 modelMatrix;

        void processModelMatrix();


    public:
        SceneItem();
        virtual ~SceneItem();

        
        void setModel(IndexedModel* m);
        IndexedModel* getModel();
        void setScale(glm::vec3 _scale);
        void setRotation(glm::vec3 _rotation);
        void setTranslation(glm::vec3 _translation);
        void setTexture(GLuint _texture);

        glm::mat4 getModelMatrix();


};

#endif // SCENEITEM_H

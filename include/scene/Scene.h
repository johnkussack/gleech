#ifndef SCENE_H
#define SCENE_H

#include <glincludes.h>
#include <vector>

#include <camera/CameraControls.h>
#include <shader.h>
#include <TextureManager.h>

#include <scene/SceneItem.h>


class Scene{

    private:

        std::vector<SceneItem*> items;
        std::vector<SceneItem*> itemsTextured;
        //std::vector<SceneModel*> models;

        GLuint vaoSolid;
        GLuint vboSolid[3];

        GLuint vaoText;
        GLuint vboText[3];

        Shader* shader;
        Shader* shaderTextures;




    public:
        Scene();
        virtual ~Scene();

        void setup(GLuint _vaoSolid,GLuint* _vboSolid, GLuint _vaoTextured, GLuint* _vboTextured, Shader* _shader, Shader* _shaderT);
        void render();
        void renderTest();

        void pushItem(SceneItem* _newItem);




};

#endif // SCENE_H

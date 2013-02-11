#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <glincludes.h>

#include <scene/SceneItem.h>

#include <shader.h>
#include <sound/soundManager.h>

#include <camera/Camera.h>
#include <camera/CameraControls.h>

#include <AntTweakBar.h>


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

        Camera* cam;
        SoundManager* soundMan;


    public:
        Scene(Camera* _cam);
        virtual ~Scene();

        void setup(GLuint _vaoSolid,GLuint* _vboSolid, GLuint _vaoTextured, GLuint* _vboTextured, Shader* _shader, Shader* _shaderT,SoundManager* sman);
        void render();
        void renderTest();

        void pushItem(SceneItem* _newItem);




};

#endif // SCENE_H

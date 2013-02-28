#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Globals.h"
#include <scene/SceneItem.h>
#include <import/IndexedModel.h>


class Scene{

    private:

        vector<SceneItem*> items;
        vector<SceneItem*> itemsTextured;
        vector<IndexedModel*> models;

        GLuint vboSolid[3];

        GLuint vboText[3];

        Globals* glb;

    public:
        Scene(Globals* _glb);
        virtual ~Scene();

        void setup(GLuint* _vboSolid, GLuint* _vboTextured);
        void render();
        void renderTest();

        void pushItem(SceneItem* _newItem);
        void pushModel(IndexedModel* _newModel);

};

#endif // SCENE_H

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Globals.h"
#include <scene/SceneItem.h>

class Scene{

    private:

        vector<SceneItem*> items;
        Globals* glb;

    public:
        Scene(Globals* _glb);
        virtual ~Scene();

        void render();

        void pushItem(SceneItem* _item);

};

#endif // SCENE_H

#ifndef LOADER_H
#define LOADER_H

#include <Globals.h>
#include <vector>
#include <scene/Scene.h>
#include <scene/SceneItem.h>

#include <import/MxoProp.h>
#include <import/MxoMga.h>
#include <import/MxoEprf.h>
#include <import/MxoIprf.h>
#include <primitives/IndexedModel.h>

class Loader{

    protected:

        Globals* glb;
        Scene* scene;
                
    public:

        Loader(Globals* _glb, Scene* _scene);

        virtual ~Loader();

        void initShaders(string vertexPath, string fragmentPath,string textureVertexPath, string textureFragmentPath);

        void loadTexture(string path, bool skybox);

        int modelIndex(string path);
        
        void addMxoMga(string path, int textureIndex, glm::vec3 translation);
        void addMxoProp(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation);
        void addMxoEprf(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation);
        void addMxoIprf(string path, int textureIndex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation);

        void addItemToScene(SceneItem* item,int textureIndex,glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation);

};



#endif // LOADER_H

#ifndef LOADER_H
#define LOADER_H

#include <Globals.h>
#include <vector>
#include <scene/Scene.h>
#include <scene/SceneItem.h>

#include <primitives/ModelVertex.h>
#include <primitives/Primitive.h>
#include <primitives/Triangle.h>
#include <primitives/Plane.h>
#include <primitives/Cube.h>
#include <primitives/Skybox.h>

#include <import/MxoProp.h>
#include <import/MxoMga.h>
#include <import/IndexedModel.h>

class Loader{

    protected:
        vector<Primitive*> primitiveStore;
       
        GLuint sceneVbo[3]; // Vertices, colors, normals?
        GLuint sceneVboTextured[3]; // Vertices, UV, normals
        Globals* glb;
        Scene* scene;
                
    public:

        Loader(Globals* _glb, Scene* _scene);

        virtual ~Loader();

        void InitShaders(string vertexPath, string fragmentPath,string textureVertexPath, string textureFragmentPath);
        void InitPrimitives();
        void LoadTexture(string path, bool skybox);
        void AddPrimitive(int index, int textureIndex,glm::vec3 scale, glm::vec3 translation);
        void AddMxoMga(string path, int textureIndex, glm::vec3 translation);
        void AddMxoProp(string path, int textureIntex, glm::vec3 scale,glm::vec3 rotation, glm::vec3 translation);


};



#endif // LOADER_H

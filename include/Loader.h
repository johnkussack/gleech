#ifndef LOADER_H
#define LOADER_H

#include <glincludes.h>
#include <vector>

#include <TextureManager.h>
#include <sound/soundManager.h>

#include <scene/Scene.h>
#include <scene/SceneItem.h>

#include <primitives/Primitive.h>
#include <primitives/Triangle.h>
#include <primitives/Plane.h>
#include <primitives/Cube.h>
#include <primitives/Skybox.h>
#include <primitives/Mesh.h>

#include <shader.h>


class Loader
{
    private:
        std::vector<Primitive*> primitiveStore;
        GLuint sceneVao;
        GLuint sceneVbo[3]; // Vertices, colors, normals?

        GLuint sceneVaoTextured;
        GLuint sceneVboTextured[3]; // Vertices, UV, normals

        TextureManager* textMan;

        SoundManager* soundM;

        Shader* shader;
        Shader* shaderTextures;

    public:
        Loader(Scene* _scene);
        virtual ~Loader();
    protected:

};

#endif // LOADER_H

#ifndef SCENE_H
#define SCENE_H

#include <glincludes.h>
#include <vector>
#include <primitives/Primitive.h>
#include <camera/CameraControls.h>
#include <shader.h>
#include <TextureManager.h>

class Scene{

    private:

        std::vector<Primitive> primitives;
        std::vector<Primitive> primitivesText;

        GLuint vaoSolid;
        GLuint vboSolid[2];

        GLuint vaoText;
        GLuint vboText[2];

        Shader* shader;
        Shader* textureShader;

        CameraControls* cam;
        TextureManager* textMan;

    public:
        Scene();
        virtual ~Scene();

        void Setup();
        void Render();
        void RenderTest();




};

#endif // SCENE_H

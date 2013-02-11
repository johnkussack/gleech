#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <glincludes.h>

#include <iostream>
#include <vector>
#include <shader.h>

class Texture{

    public:
        GLuint text;
        GLuint textId;

};

class TextureManager
{
    public:
        TextureManager(Shader* _shader);
        virtual ~TextureManager();

        void loadTexture2D(const char* imagepath, bool skybox);
        GLuint getTexture(int _index);
        GLuint getTextureId(int _index);

    protected:

    private:
        Shader* textureShader;
        std::vector<Texture*> Textures;
};

#endif // TEXTUREMANAGER_H

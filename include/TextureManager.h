#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <glincludes.h>

#include <iostream>
#include <vector>
#include <shader.h>

class TextureManager
{
    public:
        TextureManager(Shader* _shader);
        virtual ~TextureManager();

        void loadTGATexture(const char * imagepath);
        GLuint getTexture(int _index);
        GLuint getTextureId(int _index);

    protected:

    private:
        Shader* textureShader;
        std::vector<GLuint> Textures;
        std::vector<GLuint> TexturesID;
};

#endif // TEXTUREMANAGER_H

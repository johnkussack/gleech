#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <glincludes.h>

#include <iostream>
#include <vector>

using namespace std;


class TextureManager{


    private:
        vector<GLuint> Textures;
        GLuint textInt;

    public:
        TextureManager();
        virtual ~TextureManager();

        void loadTexture2DMem(unsigned char* imageData,long length);
        void loadTexture2D(const char* imagepath, bool skybox);
        GLuint getTexture(int _index);


};

#endif // TEXTUREMANAGER_H

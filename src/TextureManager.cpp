#include "TextureManager.h"

TextureManager::TextureManager(Shader* _shader){
    textureShader = _shader;
}

TextureManager::~TextureManager()
{
    Textures.clear();
    TexturesID.clear();
}

void TextureManager::loadTGATexture(const char * imagepath){
    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Read the file, call glTexImage2D with the right parameters
    glfwLoadTexture2D(imagepath, 0);

    // Nice trilinear filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);


    Textures.push_back(textureID);
    TexturesID.push_back(glGetUniformLocation(textureShader->id(), "myTextureSampler"));
    //TODO: change shader sampler name

}

GLuint TextureManager::getTexture(int _index){
    //TODO: handle outofbounds
    return Textures[_index];
}

GLuint TextureManager::getTextureId(int _index){
    //TODO: handle outofbounds
    return TexturesID[_index];
}

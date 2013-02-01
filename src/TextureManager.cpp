#include "TextureManager.h"
#include <FreeImage.h>

TextureManager::TextureManager(Shader* _shader){
    textureShader = _shader;
}

TextureManager::~TextureManager(){
    for(unsigned int i = 0;i<Textures.size();i++){
        glDeleteTextures(1,&Textures[i]);
    }
    Textures.clear();
    TexturesID.clear();
}

void TextureManager::loadTexture2D(const char* imagepath){

    FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(imagepath,0);//Automatocally detects the format(from over 20 formats!)
	FIBITMAP* image = FreeImage_Load(formato, imagepath);

	FIBITMAP* temp = image;
	image = FreeImage_ConvertTo32Bits(image);
	FreeImage_Unload(temp);

	int w = FreeImage_GetWidth(image);
	int h = FreeImage_GetHeight(image);

	printf("Texture: %s is %d x %d\n",imagepath,w,h);

	GLubyte* textureBytes = new GLubyte[4*w*h];
	char* pixels = (char*)FreeImage_GetBits(image);
	//FreeImage loads in BGR format, so you need to swap some bytes(Or use GL_BGR).

	for(int j= 0; j<w*h; j++){
		textureBytes[j*4+0]= pixels[j*4+2];
		textureBytes[j*4+1]= pixels[j*4+1];
		textureBytes[j*4+2]= pixels[j*4+0];
		textureBytes[j*4+3]= pixels[j*4+3];
		//cout<<j<<": "<<textura[j*4+0]<<"**"<<textura[j*4+1]<<"**"<<textura[j*4+2]<<"**"<<textura[j*4+3]<<endl;
	}

	//Now generate the OpenGL texture object

    GLuint texture;
    GLuint textureID;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, w, h, 0, GL_RGBA,GL_UNSIGNED_BYTE,(GLvoid*)textureBytes );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	GLenum errorLoading = glGetError();
	if(errorLoading){
		printf("There was an error loading the texture: %d\n",errorLoading);
	}
    Textures.push_back(textureID);
    TexturesID.push_back(glGetUniformLocation(textureShader->id(), "myTextureSampler"));

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

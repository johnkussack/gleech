#include "TextureManager.h"
#include <FreeImage.h>

TextureManager::TextureManager(Shader* _shader){
    textureShader = _shader;
}

TextureManager::~TextureManager(){
    for(unsigned int i = 0;i<Textures.size();i++){
        glDeleteTextures(1,&(Textures[i]->text));
        delete Textures[i];
    }
    Textures.clear();

}

void TextureManager::loadTexture2D(const char* imagepath, bool skybox){

    FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(imagepath,0);
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
	}

    Textures.push_back(new Texture());
    Texture* tp = Textures[Textures.size()-1];

	glGenTextures(1, &(tp->text));
	glBindTexture(GL_TEXTURE_2D, tp->text);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, w, h, 0, GL_RGBA,GL_UNSIGNED_BYTE,(GLvoid*)textureBytes );

    if(!skybox){
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    }
    else{
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    }

	GLenum errorLoading = glGetError();
	if(errorLoading){
		printf("There was an error loading the texture: %d\n",errorLoading);
	}else{
        printf("TM: %d %d\n",tp->text, tp->textId);
	}

}

GLuint TextureManager::getTexture(int _index){
    //TODO: handle outofbounds
    return Textures[_index]->text;
}

GLuint TextureManager::getTextureId(int _index){
    //TODO: handle outofbounds
    return Textures[_index]->textId;
}

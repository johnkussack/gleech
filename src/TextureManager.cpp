#include <TextureManager.h>
#include <FreeImage.h>

TextureManager::TextureManager(){

}

TextureManager::~TextureManager(){
    for(unsigned int i = 0;i<Textures.size();i++){
        glDeleteTextures(1,&(Textures[i]));
    }
    Textures.clear();

}

void TextureManager::loadTexture2DMem(unsigned char* imageData,long length){
    FIMEMORY* hmem = FreeImage_OpenMemory(imageData,length);
    FREE_IMAGE_FORMAT fif = FreeImage_GetFileTypeFromMemory(hmem);
    FIBITMAP* image = FreeImage_LoadFromMemory(fif, hmem, 0);
    
    FIBITMAP* temp = image;
    image = FreeImage_ConvertTo32Bits(image);
    FreeImage_Unload(temp);
    FreeImage_CloseMemory(hmem);

    int w = FreeImage_GetWidth(image);
    int h = FreeImage_GetHeight(image);


    printf("[Texture Manager] Image loaded from memory, is %d x %d\n",w,h);

    GLubyte* textureBytes = new GLubyte[4*w*h];
    char* pixels = (char*)FreeImage_GetBits(image);

    //FreeImage loads in BGR format, so we need to swap some bytes(Or use GL_BGR)

    for(int j= 0; j<w*h; j++){
            textureBytes[j*4+0]= pixels[j*4+2];
            textureBytes[j*4+1]= pixels[j*4+1];
            textureBytes[j*4+2]= pixels[j*4+0];
            textureBytes[j*4+3]= pixels[j*4+3];
    }


    glGenTextures(1, &(textInt));

    glBindTexture(GL_TEXTURE_2D, textInt);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, w, h, 0, GL_RGBA,GL_UNSIGNED_BYTE,(GLvoid*)textureBytes );



    Textures.push_back(textInt);


    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);


    GLenum errorLoading = glGetError();
    if(errorLoading){
            cout<<"There was an error loading the texture: "<<errorLoading<<endl;
    }
            
           
}

void TextureManager::loadTexture2D(const char* imagepath, bool skybox){

    FREE_IMAGE_FORMAT format = FreeImage_GetFileType(imagepath,0);
	FIBITMAP* image = FreeImage_Load(format, imagepath);

	FIBITMAP* temp = image;
	image = FreeImage_ConvertTo32Bits(image);
	FreeImage_Unload(temp);

	int w = FreeImage_GetWidth(image);
	int h = FreeImage_GetHeight(image);

	printf("[Texture Manager] Image loaded: %s is %d x %d\n",imagepath,w,h);

	GLubyte* textureBytes = new GLubyte[4*w*h];
	char* pixels = (char*)FreeImage_GetBits(image);

	//FreeImage loads in BGR format, so we need to swap some bytes(Or use GL_BGR)

	for(int j= 0; j<w*h; j++){
		textureBytes[j*4+0]= pixels[j*4+2];
		textureBytes[j*4+1]= pixels[j*4+1];
		textureBytes[j*4+2]= pixels[j*4+0];
		textureBytes[j*4+3]= pixels[j*4+3];
	}


	glGenTextures(1, &(textInt));

	glBindTexture(GL_TEXTURE_2D, textInt);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, w, h, 0, GL_RGBA,GL_UNSIGNED_BYTE,(GLvoid*)textureBytes );



	Textures.push_back(textInt);

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
		cout<<"There was an error loading the texture: "<<errorLoading<<endl;
	}

}

GLuint TextureManager::getTexture(int _index){
    //TODO: handle outofbounds
    return Textures[_index];
}



#include <Globals.h>

#define deleteifnotnull(X)    if(X!=NULL){delete X;}

Globals::Globals(){
    
    
    APPTITLE = "GLEECH V000000000.3";
    GUITITLE = "Mxo Eprf_ ExteriorPreFabs";
    APPWIDTH = 1074;
    APPHEIGHT = 768;
    
    camera = new Camera();
    camera->setResolution(APPWIDTH,APPHEIGHT);

    textMan = new TextureManager();
    soundMan = new SoundManager();
    
    soundMan->open("/root/workspace/gleechA/resources/Mxos.ogg");
    
    
}

Globals::~Globals(){
    deleteifnotnull(camera);
    deleteifnotnull(solidShader);
    deleteifnotnull(textureShader);
    deleteifnotnull(textMan);
    deleteifnotnull(soundMan);
}
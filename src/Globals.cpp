#include <Globals.h>

#define deleteifnotnull(X)    if(X!=NULL){delete X;}

Globals::Globals(){
    
    
    APPTITLE = "GLEECH V000000000.3";
    GUITITLE = "Mxo Eprf_ ExteriorPreFabs";
    APPWIDTH = 1074;
    APPHEIGHT = 768;

    camera = new Camera();
    camera->setResolution(APPWIDTH,APPHEIGHT);
    
    modelDb = new ModelDatabase();
    
    textMan = new TextureManager();
    soundMan = new SoundManager();
    
    
}

Globals::~Globals(){
    deleteifnotnull(camera);
    deleteifnotnull(solidShader);
    deleteifnotnull(textureShader);
    deleteifnotnull(modelDb);
    deleteifnotnull(textMan);
    deleteifnotnull(soundMan);
}
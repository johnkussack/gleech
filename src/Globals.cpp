#include <Globals.h>

#define deleteifnotnull(X)    if(X!=NULL){delete X;}

Globals::Globals(){
    
    
    APPTITLE = "GLEECH V000000000.3";
    GUITITLE = "Engine Optimizations. Indexed model placement tests";
    APPWIDTH = 1074;
    APPHEIGHT = 768;
    
    camera = new Camera();
    controls = new Controls();
    
    textMan = new TextureManager();
    soundMan = new SoundManager();
    
    soundMan->open("/root/workspace/gleech/resources/furious_angels.ogg");
    
    
}

Globals::~Globals(){
    deleteifnotnull(camera);
    deleteifnotnull(controls);
    deleteifnotnull(solidShader);
    deleteifnotnull(textureShader);
    deleteifnotnull(textMan);
    deleteifnotnull(soundMan);
}
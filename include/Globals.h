#ifndef GLOBALS_H
#define	GLOBALS_H

#include <iostream>
#include <glincludes.h>
#include <shader.h>
#include <camera/Camera.h>
#include <sound/soundManager.h>
#include <primitives/ModelDatabase.h>
#include <TextureManager.h>

using namespace std;

class Globals{
     
    public:
         string APPTITLE;
         string GUITITLE;
         int APPWIDTH;
         int APPHEIGHT;

         Camera* camera;
         Shader* solidShader;
         Shader* textureShader;
         TextureManager* textMan;
         SoundManager* soundMan;
         ModelDatabase* modelDb;

         Globals();
         virtual ~Globals();
};


#endif	/* GLOBALS_H */


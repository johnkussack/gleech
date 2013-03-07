// Include the APP object
#include <App.h>

// Include Luna (Lua) libraries
#include <lua/luna.h>
#include <lua/LunaLoader.h>

#include <controls/Controls.h>
#include <scene/Scene.h>
#include <Loader.h>


using namespace glm;

Loader* loader;
Scene* scene;
Controls* controls;

void resizeGL( int w, int h ) {
	glViewport( 0, 0, w, h );
	//glMatrixMode( GL_PROJECTION );
	//glLoadIdentity();
	//gluPerspective( 120.0, (GLdouble)w/(GLdouble)h, 0.5, 500.0 );
	//glMatrixMode( GL_MODELVIEW );
	///TODO
}

int main(){
        
    Globals glb;

    scene = new Scene(&glb);
    controls = new Controls(&glb);
    
    App app(&glb,scene,controls);
    
    loader = new Loader(&glb, scene);

    // Init the APP
    if(app.init()){
        
        // LUA INIT
        lua_State* L = lua_open();
        luaL_openlibs(L);

        Luna<LunaLoader>::Register(L);
        lua_pushlightuserdata(L, (void*)loader);
        lua_setglobal(L,"loader");

        if(luaL_dofile(L,"/root/workspace/gleechA/resources/init.lua")){
            cout<<"Error during load of the LUA core: "<<lua_tostring(L,-1)<<endl;
        }
        // LUA INIT END

        app.run();
        
        // Cleaning
        lua_close(L);
    }

    delete scene;
    delete loader;

    return 0;

}


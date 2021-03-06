#include <lua/LunaLoader.h>

// LUA method registering

const char LunaLoader::className[] = "LunaLoader";

#define method(class, name) {#name, &class::name}
Luna<LunaLoader>::RegType LunaLoader::methods[] = {
   method(LunaLoader, InitShaders),
   method(LunaLoader, LoadTexture),
   method(LunaLoader, AddMxoMga),
   method(LunaLoader, AddMxoProp),
   method(LunaLoader, AddMxoEprf),
   method(LunaLoader, AddMxoIprf),
   {0,0}
};

LunaLoader::LunaLoader(lua_State* L){
    loader = (Loader*) lua_touserdata(L,1);
}

// Interface for Loader methods



int LunaLoader::InitShaders(lua_State* L){
    string d = stack.PopString(L);
    string c = stack.PopString(L);
    string b = stack.PopString(L);
    string a = stack.PopString(L);

    loader->initShaders(a,b,c,d);

    return 0;
}

int LunaLoader::LoadTexture(lua_State* L){
    bool skybox = stack.PopInt(L)==1;
    string path = stack.PopString(L);
    loader->loadTexture(path,skybox);
    return 0;

}

int LunaLoader::AddMxoMga(lua_State* L){
    float z = stack.PopFloat(L);
    float y = stack.PopFloat(L);
    float x = stack.PopFloat(L);
    int tindex = stack.PopInt(L);
    string path = stack.PopString(L);
    loader->addMxoMga(path,tindex, glm::vec3(x,y,z));
    return 0;
}

int LunaLoader::AddMxoProp(lua_State* L){

    // Scale
    lua_rawgeti(L, 3, 1);
    float sx = stack.PopFloat(L);
    lua_rawgeti(L, 3, 2);
    float sy = stack.PopFloat(L);
    lua_rawgeti(L, 3, 3);
    float sz = stack.PopFloat(L);
    
    // Rotation
    lua_rawgeti(L, 4, 1);
    float rx = stack.PopFloat(L);
    lua_rawgeti(L, 4, 2);
    float ry = stack.PopFloat(L);
    lua_rawgeti(L, 4, 3);
    float rz = stack.PopFloat(L);
       
    // Translation
    lua_rawgeti(L, 5, 1);
    float tx = stack.PopFloat(L);
    lua_rawgeti(L, 5, 2);
    float ty = stack.PopFloat(L);
    lua_rawgeti(L, 5, 3);
    float tz = stack.PopFloat(L);
    
    // Texture index
    int tindex =  luaL_optinteger(L,2,0);
    
    // Path
    string path =  luaL_optstring(L,1,0);
      
    loader->addMxoProp(path,tindex, glm::vec3(sx,sy,sz), glm::vec3(rx,ry,rz), glm::vec3(tx,ty,tz));
    return 0;
}


int LunaLoader::AddMxoEprf(lua_State* L){

    // Scale
    lua_rawgeti(L, 3, 1);
    float sx = stack.PopFloat(L);
    lua_rawgeti(L, 3, 2);
    float sy = stack.PopFloat(L);
    lua_rawgeti(L, 3, 3);
    float sz = stack.PopFloat(L);
    
    // Rotation
    lua_rawgeti(L, 4, 1);
    float rx = stack.PopFloat(L);
    lua_rawgeti(L, 4, 2);
    float ry = stack.PopFloat(L);
    lua_rawgeti(L, 4, 3);
    float rz = stack.PopFloat(L);
       
    // Translation
    lua_rawgeti(L, 5, 1);
    float tx = stack.PopFloat(L);
    lua_rawgeti(L, 5, 2);
    float ty = stack.PopFloat(L);
    lua_rawgeti(L, 5, 3);
    float tz = stack.PopFloat(L);
    
    // Texture index
    int tindex =  luaL_optinteger(L,2,0);
    
    // Path
    string path =  luaL_optstring(L,1,0);
      
    loader->addMxoEprf(path,tindex, glm::vec3(sx,sy,sz), glm::vec3(rx,ry,rz), glm::vec3(tx,ty,tz));
    return 0;
}

int LunaLoader::AddMxoIprf(lua_State* L){

    // Scale
    lua_rawgeti(L, 3, 1);
    float sx = stack.PopFloat(L);
    lua_rawgeti(L, 3, 2);
    float sy = stack.PopFloat(L);
    lua_rawgeti(L, 3, 3);
    float sz = stack.PopFloat(L);
    
    // Rotation
    lua_rawgeti(L, 4, 1);
    float rx = stack.PopFloat(L);
    lua_rawgeti(L, 4, 2);
    float ry = stack.PopFloat(L);
    lua_rawgeti(L, 4, 3);
    float rz = stack.PopFloat(L);
       
    // Translation
    lua_rawgeti(L, 5, 1);
    float tx = stack.PopFloat(L);
    lua_rawgeti(L, 5, 2);
    float ty = stack.PopFloat(L);
    lua_rawgeti(L, 5, 3);
    float tz = stack.PopFloat(L);
    
    // Texture index
    int tindex =  luaL_optinteger(L,2,0);
    
    // Path
    string path =  luaL_optstring(L,1,0);
      
    loader->addMxoIprf(path,tindex, glm::vec3(sx,sy,sz), glm::vec3(rx,ry,rz), glm::vec3(tx,ty,tz));
    return 0;
}

LunaLoader::~LunaLoader(){

}

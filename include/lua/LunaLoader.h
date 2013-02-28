#ifndef LUNALOADER_H
#define LUNALOADER_H

#include <lua/luna.h>
#include <lua/luautils.hpp>
#include <Loader.h>

class LunaLoader{

    private:
        LuaStack stack;
        Loader* loader;

    public:

        static const char className[];
        static Luna<LunaLoader>::RegType methods[];

        LunaLoader(lua_State* L);
        virtual ~LunaLoader();

        // Interface for Loader methods
        int InitShaders(lua_State* L);
        int InitPrimitives(lua_State* L);
        int LoadTexture(lua_State* L);
        int AddPrimitive(lua_State* L);
        int AddMxoMga(lua_State* L);
        int AddMxoProp(lua_State* L);



};

#endif // LUNALOADER_H

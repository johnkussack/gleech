#ifndef __LUASTACK__
#define __LUASTACK__


#include "lua.h"
#include <iostream>

using namespace std;

class LuaStack{

    public:

        int PopInt(lua_State *L){

            int tmp = lua_tonumber(L, lua_gettop(L));
            lua_pop(L, 1);
            return tmp;

        }

        float PopFloat(lua_State *L){
            float tmp = lua_tonumber(L, lua_gettop(L));
            lua_pop(L, 1);
            return tmp;
        }

        string PopString(lua_State *L){
            string tmp = lua_tostring(L, lua_gettop(L));
            lua_pop(L, 1);
            return tmp;
        }

        void PushFloat(lua_State *L, float _num){
            lua_pushnumber(L,_num);
        }

        void PushInt(lua_State *L, int _num){
            lua_pushnumber(L,_num);
        }

        void PushString(lua_State *L, string _str){
            lua_pushstring(L, _str.c_str());
        }
};


#endif

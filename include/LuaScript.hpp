#ifndef _FIGHT_NIGHT_LUA_SCRIPT_HPP_
#define _FIGHT_NIGHT_LUA_SCRIPT_HPP_

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
}

namespace fightnight
{
    class LuaScript
    {
    public:
        ~LuaScript();

        static LuaScript *instance();

        lua_State *luaState();
    private:
        LuaScript();

    private:
        static LuaScript *m_sInstance;
        lua_State *m_pLuaState;
    };
} //end of namespace fightnight.

#endif // _FIGHT_NIGHT_LUA_SCRIPT_HPP_

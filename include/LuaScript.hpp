#ifndef _FIGHT_NIGHT_LUA_SCRIPT_HPP_
#define _FIGHT_NIGHT_LUA_SCRIPT_HPP_

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
}

#include <string>

namespace fightnight
{
    class LuaScript
    {
    public:
        ~LuaScript();

        static LuaScript *instance();

        lua_State *luaState();

        std::string getStringFromTable(const std::string &file_name, const std::string &table_name, const std::string &path_to_value);
        float getNumberFromTable(const std::string &file_name, const std::string &table_name, const std::string &path_to_value);
        bool getBoolFromTable(const std::string &file_name, const std::string &table_name, const std::string &path_to_value);
    private:
        LuaScript();

    private:
        static LuaScript *m_sInstance;
        lua_State *m_pLuaState;
    };
} //end of namespace fightnight.

#endif // _FIGHT_NIGHT_LUA_SCRIPT_HPP_

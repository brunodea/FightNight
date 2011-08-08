#include "LuaScript.hpp"
#include <iostream>
#include <cstdlib>

#include "util/util.hpp"

using namespace fightnight;

LuaScript *LuaScript::m_sInstance = NULL;

LuaScript::LuaScript()
{
    m_pLuaState = lua_open();
}

LuaScript::~LuaScript()
{
    lua_close(m_pLuaState);
}

LuaScript *LuaScript::instance()
{
    if(m_sInstance == NULL)
        m_sInstance = new LuaScript();
    return m_sInstance;
}

lua_State *LuaScript::luaState()
{
    return m_pLuaState;
}

std::string LuaScript::getStringFromTable(const std::string &file_name, const std::string &table_name,
                                          const std::string &path_to_value)
{
    if(luaL_loadfile(m_pLuaState,file_name.c_str()) || lua_pcall(m_pLuaState,0,0,0))
    {
        std::cout << lua_tostring(m_pLuaState,-1) << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> path = util::split(path_to_value, '.');

    lua_getglobal(m_pLuaState, table_name.c_str());

    for(unsigned int i = 0; i < path.size(); i++)
    {
        int v;
        if(util::convert(path.at(i), v))
            lua_pushnumber(m_pLuaState, v);
        else
            lua_pushstring(m_pLuaState, path.at(i).c_str());
        lua_gettable(m_pLuaState, -2);
    }

    std::string res = lua_tostring(m_pLuaState, -1);
    lua_pop(m_pLuaState, path.size()+1);

    return res;
}

float LuaScript::getNumberFromTable(const std::string &file_name, const std::string &table_name,
                                const std::string &path_to_value)
{
    if(luaL_loadfile(m_pLuaState,file_name.c_str()) || lua_pcall(m_pLuaState,0,0,0))
    {
        std::cout << lua_tostring(m_pLuaState,-1) << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> path = util::split(path_to_value, '.');

    lua_getglobal(m_pLuaState, table_name.c_str());

    for(unsigned int i = 0; i < path.size(); i++)
    {
        int v;
        if(util::convert(path.at(i), v))
            lua_pushnumber(m_pLuaState, v);
        else
            lua_pushstring(m_pLuaState, path.at(i).c_str());
        lua_gettable(m_pLuaState, -2);
    }

    float res = lua_tonumber(m_pLuaState, -1);
    lua_pop(m_pLuaState, path.size()+1);

    return res;
}

bool LuaScript::getBoolFromTable(const std::string &file_name, const std::string &table_name,
                                 const std::string &path_to_value)
{
    if(luaL_loadfile(m_pLuaState,file_name.c_str()) || lua_pcall(m_pLuaState,0,0,0))
    {
        std::cout << lua_tostring(m_pLuaState,-1) << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> path = util::split(path_to_value, '.');

    lua_getglobal(m_pLuaState, table_name.c_str());

    for(unsigned int i = 0; i < path.size(); i++)
    {
        int v;
        if(util::convert(path.at(i), v))
            lua_pushnumber(m_pLuaState, v);
        else
            lua_pushstring(m_pLuaState, path.at(i).c_str());
        lua_gettable(m_pLuaState, -2);
    }

    bool res = lua_toboolean(m_pLuaState, -1);
    lua_pop(m_pLuaState, path.size()+1);

    return res;
}

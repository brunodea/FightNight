#include "LuaScript.hpp"

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

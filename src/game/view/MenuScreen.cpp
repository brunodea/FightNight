#include "game/view/MenuScreen.h"
#include "LuaScript.hpp"
#include "macros.h"

using namespace game;
using namespace view;
using namespace fightnight;

MenuScreen::MenuScreen(const Point2 &initPos)
    : m_OptionsInitPos(initPos)
{
}

MenuScreen::MenuScreen(const std::string &lua_screen_var_name, const Point2 &initPos)
    : m_OptionsInitPos(initPos)
{
    if(luaL_loadfile(LUA_STATE,"../resources/scripts/menuscreen.lua") || lua_pcall(LUA_STATE,0,0,0))
    {
        std::cout << lua_tostring(LUA_STATE,-1) << std::endl;
        return;
    }
    int size = 0;

    lua_getglobal(LUA_STATE, lua_screen_var_name.c_str());
    lua_pushstring(LUA_STATE, "size");
    lua_gettable(LUA_STATE, -2);
    size = lua_tonumber(LUA_STATE,-1);
    lua_pop(LUA_STATE,1);

    for(int i = 1; i <= size; i++)
    {
        lua_pushnumber(LUA_STATE,i);
        lua_gettable(LUA_STATE, -2);

        lua_pushstring(LUA_STATE, "text");

        lua_gettable(LUA_STATE,-2);
        std::string text = lua_tostring(LUA_STATE, -1);

        lua_pop(LUA_STATE, 1);
        lua_pushstring(LUA_STATE,"font");

        lua_gettable(LUA_STATE,-2);
        std::string font = lua_tostring(LUA_STATE, -1);

        lua_pop(LUA_STATE, 1);
        lua_pushstring(LUA_STATE,"fontsize");

        lua_gettable(LUA_STATE, -2);
        int fontsize = lua_tonumber(LUA_STATE, -1);

        lua_pop(LUA_STATE,2);

        addOption(new MenuOption(text, font, fontsize, true));
    }
    lua_pop(LUA_STATE,3);
}

MenuScreen::~MenuScreen()
{
    for(unsigned int i = 0; i < m_Options.size(); i++)
        delete m_Options.at(i);
}

void MenuScreen::addOption(MenuOption *option)
{
    unsigned int size = m_Options.size();
    int h = 0;
    for(unsigned int i = 0; i < size; i++)
    {
        boost::polygon::interval_data<int> hid = boost::polygon::get(option->rect(), boost::polygon::VERTICAL);
        h += hid.high()-hid.low() + 3;
    }
    Point2 p(m_OptionsInitPos.get(boost::polygon::HORIZONTAL),m_OptionsInitPos.get(boost::polygon::VERTICAL) + h);
    Rectangle r = option->rect();

    boost::polygon::convolve(r, p);
    option->setRect(r);
    m_Options.push_back(option);
}

void MenuScreen::draw(float r, float g, float b, float a)
{
    for(unsigned int i = 0; i < m_Options.size(); i++)
        m_Options.at(i)->draw(r,g,b,a);
}

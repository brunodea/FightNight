#include "game/view/MenuScreen.h"
#include "LuaScript.hpp"
#include "macros.h"

#include <string>
#include <sstream>

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
    std::string filename = "../resources/scripts/menuscreen.lua";

    int size = (int)LUA->getNumberFromTable(filename, lua_screen_var_name, "size");
    for(int i = 1; i <= size; i++)
    {
        std::string val;
        std::stringstream ss;
        ss << i;
        ss >> val;
        std::string text = LUA->getStringFromTable(filename, lua_screen_var_name, val+".text");
        std::string font = LUA->getStringFromTable(filename, lua_screen_var_name, val+".font");
        int fontsize = (int)LUA->getNumberFromTable(filename, lua_screen_var_name, val+".fontsize");
        bool clickable = LUA->getBoolFromTable(filename, lua_screen_var_name, val+".clickable");

        float w = LUA->getNumberFromTable(filename, lua_screen_var_name, val+".rect.width");
        float h = LUA->getNumberFromTable(filename, lua_screen_var_name, val+".rect.height");

        float x = LUA->getNumberFromTable(filename, lua_screen_var_name, val+".rect.x");
        float y = LUA->getNumberFromTable(filename, lua_screen_var_name, val+".rect.y");

        addOption(new MenuOption(text, Rectangle(x,y,w,-1*h), font, fontsize, clickable));
    }
}

MenuScreen::~MenuScreen()
{
    for(unsigned int i = 0; i < m_Options.size(); i++)
        delete m_Options.at(i);
}

void MenuScreen::addOption(MenuOption *option)
{
    unsigned int size = m_Options.size();
    float h = 0;
    for(unsigned int i = 0; i < size; i++)
    {
        polygon_interval hid = boost::polygon::get(option->rect(), boost::polygon::VERTICAL);
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

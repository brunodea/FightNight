#include "game/view/MenuScreen.h"
#include "LuaScript.hpp"
#include "macros.h"
#include "Mouse.hpp"

#include <string>
#include <sstream>

using namespace game;
using namespace view;
using namespace fightnight;

MenuScreen::MenuScreen(const Point2 &initPos)
    : m_OptionsInitPos(initPos)
{
}

MenuScreen::MenuScreen(const std::string &lua_screen_var_name)
{
    std::string filename = "../resources/scripts/menuscreen.lua";

    float posx = LUA->getNumberFromTable(filename, lua_screen_var_name, "position.x");
    float posy = LUA->getNumberFromTable(filename, lua_screen_var_name, "position.y");

    Point2 pos(posx, posy);
    m_OptionsInitPos = pos;

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

        addOption(new MenuOption(text, Rectangle(Point2(x,y),Point2(x+w,y+h)), font, fontsize, clickable));
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

    Rectangle r = option->rect();
    for(unsigned int i = 0; i < size; i++)
        h += r.max_corner().y();
    Point2 p(m_OptionsInitPos.x(), m_OptionsInitPos.y() + h);

    Point2 nmin(r.min_corner().x()+p.x(), r.min_corner().y()+p.y());
    Point2 nmax(r.max_corner().x()+p.x(), r.max_corner().y()+p.y());

    option->setRect(Rectangle(nmin, nmax));
    m_Options.push_back(option);
}

void MenuScreen::draw(float r, float g, float b, float a)
{
    for(unsigned int i = 0; i < m_Options.size(); i++)
        m_Options.at(i)->draw(r,g,b,a);
}

void MenuScreen::onMouseMove(int x, int y)
{
    for(unsigned int i = 0; i < m_Options.size(); i++)
        m_Options.at(i)->setMouseOver(x, y);
}

void MenuScreen::onMouseClick(int button, int state)
{
    if(state == GLFW_PRESS)
    {
        if(button == GLFW_MOUSE_BUTTON_1)
        {
            for(unsigned int i = 0; i < m_Options.size(); i++)
            {
                if(m_Options.at(i)->isMouseOver())
                    std::cout << "Mouse clicked in " << m_Options.at(i)->text() << std::endl;
            }
        }
    }
}


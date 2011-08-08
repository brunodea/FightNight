#include "game/view/MenuScreen.h"

using namespace game;
using namespace view;

MenuScreen::MenuScreen(const Point2 &initPos)
    : m_OptionsInitPos(initPos)
{
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

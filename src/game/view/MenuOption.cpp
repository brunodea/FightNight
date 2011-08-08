#include "game/view/MenuOption.h"
#include "glfw.h"
#include <iostream>

#include "util/GameFont.hpp"

using namespace game;
using namespace view;

MenuOption::MenuOption(const std::string &text, const Rectangle &rect, const std::string &font, int fontsize, bool clickable)
    : m_Text(text), m_Font(font), m_iFontSize(fontsize), m_bClickable(clickable), m_BoundingRect(rect)
{
}

MenuOption::MenuOption(const std::string &text, const std::string &font, int fontsize, bool clickable)
    : m_Text(text), m_Font(font), m_iFontSize(fontsize), m_bClickable(clickable)
{
    int w = text.size()*fontsize;
    int h = fontsize;
    m_BoundingRect = Rectangle(w/-2,h/2,w/2,h/-2);

    /*
    boost::polygon::interval_data<int> ww = boost::polygon::get(m_BoundingRect, boost::polygon::HORIZONTAL);
    std::cout << "w low:" << ww.low() << " ";
    std::cout << "w high:" << ww.high() << std::endl;*/
}

void MenuOption::draw(float r, float g, float b, float a)
{
    boost::polygon::interval_data<int> w = boost::polygon::get(m_BoundingRect, boost::polygon::HORIZONTAL);
    boost::polygon::interval_data<int> h = boost::polygon::get(m_BoundingRect, boost::polygon::VERTICAL);

    glColor4f(r, g, b, a);

    glPushMatrix();
        glTranslated(w.low()+((w.high()-w.low())/4),h.low(),0);
        fightnight::util::GAME_FONT->drawText(m_Text, m_Font, m_iFontSize);
    glPopMatrix();

    glColor4f(1.f,0.f,0.f,.3f);
    glBegin(GL_QUADS);
        glVertex2d(w.low(),h.low());
        glVertex2d(w.high(),h.low());
        glVertex2d(w.high(),h.high());
        glVertex2d(w.low(),h.high());
    glEnd();
}

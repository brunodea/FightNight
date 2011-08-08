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
    float w = text.size()*(fontsize-(fontsize/4));
    float h = fontsize;
    m_BoundingRect = Rectangle(0,0,w,-1*h);
}

void MenuOption::draw(float r, float g, float b, float a)
{
    polygon_interval w = boost::polygon::get(m_BoundingRect, boost::polygon::HORIZONTAL);
    polygon_interval h = boost::polygon::get(m_BoundingRect, boost::polygon::VERTICAL);

    glColor4f(r, g, b, a);

    glPushMatrix();
        glTranslated(w.low(),h.low(),0);
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

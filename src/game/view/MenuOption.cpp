#include "game/view/MenuOption.h"
#include "glfw.h"

#include "util/GameFont.hpp"

using namespace game;
using namespace view;

MenuOption::MenuOption(const std::string &text, const Point2 &pos, const Rectangle &rect,
                   const std::string &font, int fontsize, bool clickable)
    : m_Text(text), m_Font(font), m_iFontSize(fontsize), m_bClickable(clickable), m_Pos(pos), m_BoundingRect(rect)
{
    boost::polygon::convolve(m_BoundingRect, m_Pos);
}

MenuOption::MenuOption(const std::string &text, const Point2 &pos, const std::string &font, int fontsize, bool clickable)
    : m_Text(text), m_Font(font), m_iFontSize(fontsize), m_bClickable(clickable), m_Pos(pos)
{
    int w = text.size()*fontsize;
    int h = fontsize;
    m_BoundingRect = Rectangle(w/-2,h/2,w/2,h/-2);
    boost::polygon::convolve(m_BoundingRect, m_Pos);
}

void MenuOption::draw()
{
    boost::polygon::interval_data<int> w = boost::polygon::get(m_BoundingRect, boost::polygon::HORIZONTAL);
    boost::polygon::interval_data<int> h = boost::polygon::get(m_BoundingRect, boost::polygon::VERTICAL);

    glColor4f(1.f,1.f,1.f,1.f);

    glPushMatrix();
        glTranslated(w.low(),h.low(),0);
        fightnight::util::GAME_FONT->drawText(m_Text, m_Font, m_iFontSize);
    glPopMatrix();

    glColor4f(1.f,0.f,0.f,.3f);
    glBegin(GL_QUADS);
        glVertex2d(w.low(),h.low());
        glVertex2d(w.low(),h.high());
        glVertex2d(w.high(),h.high());
        glVertex2d(w.high(),h.low());
    glEnd();
}

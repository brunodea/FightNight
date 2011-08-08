#ifndef _FIGHT_NIGHT_MENU_OPTION_H_
#define _FIGHT_NIGHT_MENU_OPTION_H_

#include <string>
#include <boost/polygon/polygon.hpp>
#include <gltext.h>
#include "macros.h"

namespace game
{
namespace view
{
    class MenuOption
    {
    public:
        MenuOption(const std::string &text, const Rectangle &rect,
                   const std::string &font, int fontsize, bool clickable = false);
        MenuOption(const std::string &text, const std::string &font, int fontsize, bool clickable = false);

        void draw(float r = 1.f, float g = 1.f, float b = 1.f, float a = 1.f);

        inline Rectangle rect() { return m_BoundingRect; }
        inline void setRect(const Rectangle &rect) { m_BoundingRect = rect; }

        inline bool isMouseOver() { return m_bMouseIsOver; }
        inline void setMouseOver(int mouse_x, int mouse_y)
        {
            m_bMouseIsOver = boost::geometry::within(Point2(mouse_x, mouse_y), m_BoundingRect);
        }

        std::string text() { return m_Text; }

    private:
        std::string m_Text;
        std::string m_Font;
        int m_iFontSize;
        bool m_bClickable;

        Rectangle m_BoundingRect;

        bool m_bMouseIsOver;
    };
}
}
#endif // _FIGHT_NIGHT_MENU_OPTION_H_

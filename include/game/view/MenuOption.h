#ifndef _FIGHT_NIGHT_MENU_OPTION_H_
#define _FIGHT_NIGHT_MENU_OPTION_H_

#include <string>
#include <boost/polygon/polygon.hpp>
#include "macros.h"

namespace game
{
namespace view
{
    class MenuOption
    {
    public:
        MenuOption(const std::string &text, const Point2 &pos, const Rectangle &rect, bool clickable = false);
        MenuOption(const std::string &text, const Point2 &pos, bool clickable = false);

        void draw();

        inline Point2 pos() { return m_Pos; }
        inline void setPos(const Point2 &pos)
        {
            m_Pos = pos;
            boost::polygon::interval_data<int> w = boost::polygon::get(m_BoundingRect, boost::polygon::HORIZONTAL);
            boost::polygon::interval_data<int> h = boost::polygon::get(m_BoundingRect, boost::polygon::VERTICAL);

            m_BoundingRect = Rectangle(w.low(),h.low(),w.high(),h.high());
            boost::polygon::convolve(m_BoundingRect, m_Pos);
        }

        inline Rectangle rect() { return m_BoundingRect; }
        inline void setRect(const Rectangle &rect)
        {
            m_BoundingRect = rect;
            boost::polygon::convolve(m_BoundingRect, m_Pos);
        }

    private:
        std::string m_Text;
        bool m_bClickable;

        Point2 m_Pos;
        Rectangle m_BoundingRect;
    };
}
}
#endif // _FIGHT_NIGHT_MENU_OPTION_H_

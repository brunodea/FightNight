#ifndef _FIGHT_NIGHT_MENU_SCREEN_H_
#define _FIGHT_NIGHT_MENU_SCREEN_H_

#include <vector>
#include <boost/polygon/polygon.hpp>
#include <string>
#include "macros.h"
#include "game/view/MenuOption.h"

namespace game
{
namespace view
{
    class MenuScreen
    {
    public:
        MenuScreen(const Point2 &initPos);
        MenuScreen(const std::string &lua_var_name);
        ~MenuScreen();

        void addOption(MenuOption *option);
        void draw(float r = 1.f, float g = 1.f, float b = 1.f, float a = 1.f);

        void onMouseMove(int x, int y);
        void onMouseClick(int button, int state);

    private:
        std::vector<MenuOption *> m_Options;
        Point2 m_OptionsInitPos;
    };
}
}

#endif // _FIGHT_NIGHT_MENU_SCREEN_H_

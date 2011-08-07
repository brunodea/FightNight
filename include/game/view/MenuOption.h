#ifndef _FIGHT_NIGHT_MENU_OPTION_H_
#define _FIGHT_NIGHT_MENU_OPTION_H_

#include <string>

namespace game
{
namespace view
{
    class MenuOption
    {
    public:
        MenuOption(const std::string &text, bool clickable = false);

    private:
        std::string m_Text;
        bool m_bClickable;
    };
}
}
#endif // _FIGHT_NIGHT_MENU_OPTION_H_

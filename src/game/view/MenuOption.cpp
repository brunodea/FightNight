#include "MenuOption.h"

using namespace game;
using namespace view;

MenuOption::MenuOption(const std::string &text, bool clickable)
    : m_Text(text), m_bClickable(clickable)
{
}

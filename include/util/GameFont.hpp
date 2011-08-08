#ifndef _FIGHT_NIGHT_GAME_FONT_HPP_
#define _FIGHT_NIGHT_GAME_FONT_HPP_

#include <gltext.h>
#include <map>
#include <string>

namespace fightnight
{
namespace util
{
    class GameFont
    {
    public:
        static GameFont *instance();

        void drawText(const std::string &text, const std::string &font, int fontsize);
    private:
        GameFont();

    private:
        static GameFont *m_sInstance;

        std::map<std::string, std::pair<int, gltext::FontRendererPtr> > m_Map;
    }; //end of class GameFont.
} //end of namespace util.
} //end of namespace fightnight.

#endif

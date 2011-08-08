#include "util/GameFont.hpp"

using namespace fightnight;
using namespace util;

GameFont *GameFont::m_sInstance = NULL;

GameFont::GameFont()
    : m_Map()
{
}

GameFont *GameFont::instance()
{
    if(m_sInstance == NULL)
        m_sInstance = new GameFont();
    return m_sInstance;
}

void GameFont::drawText(const std::string &text, const std::string &font, int fontsize)
{
    std::map<std::string, std::pair<int, gltext::FontRendererPtr> >::iterator it = m_Map.find(font);
    if(it == m_Map.end() || ((*it).second.first != fontsize))
    {
        gltext::FontRendererPtr f = gltext::CreateRenderer(gltext::PIXMAP, gltext::OpenFont(font.c_str(), fontsize));
        std::pair<int, gltext::FontRendererPtr> p = std::pair<int, gltext::FontRendererPtr>(fontsize, f);
        m_Map.insert(std::pair<std::string, std::pair<int, gltext::FontRendererPtr> >(font,p));
        it = m_Map.find(font);
    }

    GLTEXT_STREAM((*it).second.second) << text;
}

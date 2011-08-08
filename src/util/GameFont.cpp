#include "util/GameFont.hpp"
#include <iostream>

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
    gltext::FontRendererPtr fontRendererPtr;
    std::map<std::string, std::vector<std::pair<int, gltext::FontRendererPtr> > >::iterator it = m_Map.find(font);
    if(it == m_Map.end())
    {
        gltext::FontRendererPtr f = gltext::CreateRenderer(gltext::PIXMAP, gltext::OpenFont(font.c_str(), fontsize));
        std::pair<int, gltext::FontRendererPtr> p = std::pair<int, gltext::FontRendererPtr>(fontsize, f);
        std::vector<std::pair<int, gltext::FontRendererPtr> >v;
        v.push_back(p);

        m_Map.insert(std::pair<std::string,std::vector<std::pair<int, gltext::FontRendererPtr> > >(font,v));
        fontRendererPtr = f;
    }
    else
    {
        bool diff_fsize = true;
        std::vector<std::pair<int, gltext::FontRendererPtr> >aux;
        std::vector<std::pair<int, gltext::FontRendererPtr> >::iterator vit;
        for(vit = (*it).second.begin(); vit != (*it).second.end(); vit++)
        {
            if((*vit).first == fontsize)
            {
                fontRendererPtr = (*vit).second;
                diff_fsize = false;
                break;
            }
            aux.push_back((*vit));
        }

        if(diff_fsize)
        {
            gltext::FontRendererPtr f = gltext::CreateRenderer(gltext::PIXMAP, gltext::OpenFont(font.c_str(), fontsize));
            aux.push_back(std::pair<int, gltext::FontRendererPtr>(fontsize, f));
            m_Map.insert(std::pair<std::string,std::vector<std::pair<int, gltext::FontRendererPtr> > >(font,aux));

            fontRendererPtr = f;
        }
    }

    GLTEXT_STREAM(fontRendererPtr) << text;
}

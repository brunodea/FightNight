#ifndef _FIGHT_NIGHT_UTIL_HPP_
#define _FIGHT_NIGHT_UTIL_HPP_

#include <vector>
#include <string>
#include <sstream>

namespace fightnight
{
namespace util
{
    inline std::vector<std::string> &splitaux(const std::string &s, char delim, std::vector<std::string> &elems)
    {
        std::stringstream ss(s);
        std::string item;
        while(std::getline(ss, item, delim))
        {
            elems.push_back(item);
        }
        return elems;
    }


    inline std::vector<std::string> split(const std::string &s, char delim)
    {
        std::vector<std::string> elems;
        return splitaux(s, delim, elems);
    }

    // This function returns true if the number is valid
    // and sets Res to the correct number
    template<typename T>
    inline bool convert(const std::string& a, T& res)
    {
        std::istringstream iss(a);
        iss>>res;
        return (iss.fail() || iss.tellg()!=a.length()) ? false : true;
    }
}
}

#endif

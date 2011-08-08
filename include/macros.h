#ifndef _FIGHT_NIGHT_MACROS_H_
#define _FIGHT_NIGHT_MACROS_H_

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define CONTROLLER GameController::instance()
#define LUA LuaScript::instance()
#define LUA_STATE LUA->luaState()

#define GAME_FONT GameFont::instance()

#include <boost/polygon/polygon.hpp>
typedef boost::polygon::point_data<int> Point2;
typedef boost::polygon::rectangle_data<int> Rectangle;

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
}

#endif

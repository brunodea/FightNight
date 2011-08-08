#ifndef _FIGHT_NIGHT_MACROS_H_
#define _FIGHT_NIGHT_MACROS_H_

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define CONTROLLER GameController::instance()
#define LUA LuaScript::instance()
#define LUA_STATE LUA->luaState()

#define GAME_FONT GameFont::instance()

#include "glfw.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/box.hpp>
typedef boost::geometry::model::d2::point_xy<float> Point2;
typedef boost::geometry::model::box<Point2> Rectangle;

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
}

#endif

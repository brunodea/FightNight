#include <cstdlib>
#include <iostream>
#include "glfw.h"

#include "macros.h"
#include "GameController.h"
#include "LuaScript.hpp"
#include "util/GameFont.hpp"

using namespace fightnight;

/*
 * Callback functions
 */
void GLFWCALL mousePosCallback(int x, int y)
{
}

void GLFWCALL keyEventCallback(int key, int state)
{
}

void GLFWCALL handleResize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void setCallBacks()
{
    glfwSetMousePosCallback(mousePosCallback);
    glfwSetKeyCallback(keyEventCallback);
    glfwSetWindowSizeCallback(handleResize);
}

void initOpenGL()
{
    int w, h;

    glfwGetWindowSize(&w, &h);

    handleResize(w, h);
    glClearColor(0.f, 0.f, 0.f, 1.f);
}

void clear()
{
    delete CONTROLLER;
    delete LUA;
    delete util::GAME_FONT;
}

int main()
{
    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    if(!glfwOpenWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 8, 8, 8, 8, 8, 8, GLFW_WINDOW))
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    initOpenGL();
    setCallBacks();

    fightnight::LUA; //inicializa lua.
    fightnight::CONTROLLER->run();

    exit(EXIT_SUCCESS);
}

#include "GameController.h"
#include "glfw.h"

#include "game/view/MenuOption.h"
#include "macros.h"

using namespace fightnight;

GameController *GameController::m_sInstance = 0;

GameController::GameController()
    : m_bRunning(true)
{
}

GameController *GameController::instance()
{
    if(m_sInstance == 0)
        m_sInstance = new GameController();
    return m_sInstance;
}

void GameController::run()
{
    double last_render = 0;
    double last_update = 0;

    double frame_interval = 1.f/60.f;
    double update_interval = 1.f/90.f;

    double cur_time = 0;
    while(m_bRunning)
    {
        cur_time = glfwGetTime();
        if(cur_time - last_update > update_interval)
        {
            onUpdate();
            last_update = glfwGetTime();
        }
        if(cur_time - last_render > frame_interval)
        {
            last_render = glfwGetTime();
            onRender();
            glfwSwapBuffers();
        }

        m_bRunning = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
        glfwSleep(update_interval - (cur_time + glfwGetTime()));
    }
}

void GameController::onRender()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    game::view::MenuOption m("lol", Point2(100,100), Rectangle(0,0,20,20));
    m.draw();
}

void GameController::onUpdate()
{
}

void GameController::onKeyEvent(int key, int state)
{
}

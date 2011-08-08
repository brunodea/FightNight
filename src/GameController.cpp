#include "GameController.h"
#include "glfw.h"

#include "macros.h"

using namespace fightnight;

GameController *GameController::m_sInstance = 0;

GameController::GameController()
    : m_bRunning(true), m_TitleScreen(std::string("title_screen"))
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_TitleScreen.draw();

    glDisable(GL_BLEND);
}

void GameController::onUpdate()
{
}

void GameController::onKeyEvent(int key, int state)
{
}

void GameController::onMouseMoveEvent(int x, int y)
{
    m_TitleScreen.onMouseMove(x, y);
}

void GameController::onMouseButtonEvent(int button, int state)
{
    m_TitleScreen.onMouseClick(button, state);
}

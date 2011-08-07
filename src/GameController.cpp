#include "GameController.h"

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
}

void GameController::onRender()
{
}

void GameController::onUpdate()
{
}

void GameController::onKeyEvent(int key, int state)
{
}

#ifndef _FIGHT_NIGHT_GAME_CONTROLLER_H
#define _FIGHT_NIGHT_GAME_CONTROLLER_H

namespace fightnight
{
    class GameController
    {
    public:
        static GameController *instance();

        void run();

        void onRender();
        void onUpdate();
        void onKeyEvent(int key, int state);

    private:
        GameController();

    private:
        static GameController *m_sInstance;
        bool m_bRunning;

    }; //end of class GameController.
} //end of namespace fightnight.
#endif // _FIGHT_NIGHT_GAME_CONTROLLER_H

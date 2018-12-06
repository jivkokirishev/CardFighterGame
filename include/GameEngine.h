#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "MenuState.h"
#include "BattleState.h"

class GameEngine
{
    public:
        GameEngine();
        void stateManager();

    private:
        vector<Hero> heroList;
        int state;
        void setState(int);

        MenuState menu;     /// 1
        BattleState battle; /// 2
};

#endif // GAMEENGINE_H

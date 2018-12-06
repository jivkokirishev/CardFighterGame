#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "Battle.h"
#include "Hero.h"

class BattleState
{
    private:
        Battle game;
    public:
        bool gameLoop(Hero, int, Hero, int);
};

#endif // BATTLESTATE_H

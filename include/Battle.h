#ifndef BATTLE_H
#define BATTLE_H

#include "Player.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>

using namespace std;


class Battle
{
    private:
        bool gameOver;
        bool endTurn;
        int turn;
        bool played;
        int mana;
        int gameLayers;

        /// Draw
        void drawHand();
        void drawBoard();
        void drawMana();
        void showOptions();

        /// Input
        unsigned option;
        unsigned marks[2];
    public:
        Battle();

        /// Draw
        void draw();
        /// Input
        void analyzeInput();
        /// Update
        void nonPlayerAction();
        void handleAction();

        bool getEndTurn();
        Player pOne;
        Player pTwo;
};

#endif // BATTLE_H

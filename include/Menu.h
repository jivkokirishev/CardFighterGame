#ifndef MENU_H
#define MENU_H

#define SLEEP_TIME 250
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "../include/Hero.h"

using namespace std;

class Menu
{
    private:
        int index;
        bool startBattle;
        bool endGame;
        string name;
        int menuLayers;

        Hero createHero(string);
    public:
        Menu();

        void setStart(bool);
        void setEnd(bool);

        bool getStart();
        bool getEnd();

        void showMenu();
        void getCommand();
        void proceed(vector<Hero>*);

};

#endif // MENU_H

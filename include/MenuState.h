#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "../include/Menu.h"


class MenuState
{
    private:
        Menu gameMenu;
        vector<Hero> heroList;
    public:
        MenuState();

        void setHeroList(vector<Hero>);
        vector<Hero> getHeroList();
        int menuLoop();
};

#endif // MENUSTATE_H

#include "../include/MenuState.h"

MenuState::MenuState()
{

}

void MenuState::setHeroList(vector<Hero> heroMainList)
{
    for (unsigned i = 0; i < heroMainList.size(); i++)
    {
        this -> heroList.push_back(heroMainList.at(i));
    }
}

vector<Hero> MenuState::getHeroList()
{
    return this -> heroList;
}

int MenuState::menuLoop()
{
    while (!gameMenu.getEnd() && !gameMenu.getStart())
    {
        gameMenu.showMenu();
        gameMenu.getCommand();
        gameMenu.showMenu();
        gameMenu.proceed(&this -> heroList);
    }
    if (gameMenu.getEnd()) return 0;
    else return 2;
}

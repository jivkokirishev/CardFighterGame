#include "include/GameEngine.h"
int main()
{

    /** MenuState TEST

        Hero test;
        test.setName("test");

        vector<Hero> testList;
        testList.push_back(test);

        MenuState testMenuState;
        testMenuState.setHeroList(testList);
        int a = testMenuState.menuLoop();
        cout << a;
    **/

    /** CardList TEST
    CardList cards;
    vector<Card*> listCards;
    listCards = cards.loadCardList();
    //cout << "Done: 1" << endl;
    //cout << listCards.size() << endl;
    //cout << listCards.at(0).ToStream() << endl;
    for (unsigned i = 0; i < listCards.size(); i++)
    {
        ///cout << "Done: 2" << endl;
        cout << listCards.at(i) -> ToStream() << endl;
    }
    //cout << "Done: 3" << endl;
    **/

    /** GameEngine TEST*/
    GameEngine cardGame;
    cardGame.stateManager();

}


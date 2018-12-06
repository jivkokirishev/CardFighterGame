#include "../include/BattleState.h"

bool BattleState::gameLoop(Hero hOne, int indexOfDeckOne, Hero hTwo, int indexOfDeckTwo)
{
    cout << "Error!" << endl;
    game.pOne.setHP(40);
    game.pOne.set_name(hOne.getName());
    game.pOne.set_shuffle_deck(hOne.getDecks().at(indexOfDeckOne));

    game.pTwo.setHP(40);
    game.pTwo.set_name(hTwo.getName());
    game.pTwo.set_shuffle_deck(hTwo.getDecks().at(indexOfDeckTwo));

    while(game.pOne.get_HP() > 0 || game.pTwo.get_HP() > 0)
    {
        if (game.getEndTurn()) game.nonPlayerAction();
        game.draw();
        game.analyzeInput();
        game.handleAction();
    }

    return true;
}

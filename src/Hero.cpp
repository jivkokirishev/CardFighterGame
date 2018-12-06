#include "../include/Hero.h"

Hero::Hero()
{

}

void Hero::setName(string name)
{
    this -> name = name;
}

string Hero::getName()
{
    return this -> name;
}

void Hero::createDeck(string deckName)
{
        DeckStructure* deck = new DeckStructure(deckName);
		int command;
		int i = 0, index;
		while (i <= deck -> getMaxSize()){
			cout << "Enter 1 to add a card or 2 to remove a card: ";
			cin  >> command;

			// TODO: Have the user interact with the program in the addCard and removeCard methods
			switch(command){
				case 1: {
				    cin >> index;
  					deck -> addCard(index);
  					i++;
  					break;
				}
				case 2: {
				    cin >> index;
  					deck -> removeCard(index);
  					i--;
  					break;
                }
				default: {
					cout << "Wrong command\n";
					continue;
				}
			}

			cout << i << " card(s) in deck\n";
		};

		deckList.push_back(*deck);
}

vector<DeckStructure> Hero::getDecks()
{
    return this -> deckList;
}

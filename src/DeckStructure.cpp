#include "../include/DeckStructure.h"

DeckStructure::DeckStructure()
{
    this -> id = ++deckCounter;
    this -> name = "";
    this -> maxSize = 2;
}

DeckStructure::DeckStructure(string name)
{
    this -> id = ++deckCounter;
    this -> name = name;
    this -> maxSize = 2;
}

void DeckStructure::setName(string name)
{
    this -> name = name;
}

void DeckStructure::addCard(int cardId)
{
    if(this -> maxSize > this -> deckList.size())
    {
        deckList.push_back(cardId);
    }
    else
    {
        cout << "You are trying to add more cards than allowed in your deck!" << endl;
    }
}

void DeckStructure::removeCard(int cardId)
{
    int isFound = false;
    for(unsigned i = 0; i < this -> deckList.size(); i++)
    {
        if(cardId == deckList.at(i))
        {
            deckList.erase(deckList.begin() + i);
            isFound = true;
            break;
        }
    }
    if(!isFound) cout<<"Card not found in the deck, try another one!"<<endl;
}

unsigned int DeckStructure::getId()
{
    return this -> id;
}

int DeckStructure::getMaxSize()
{
    return this -> maxSize;
}

string DeckStructure::getName()
{
    return this -> name;
}

vector<int> DeckStructure::getDeck()
{
    return this -> deckList;
}

int DeckStructure::deckCounter = 0;

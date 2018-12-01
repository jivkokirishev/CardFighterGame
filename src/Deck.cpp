#include<iostream>
#include<vector>
#include<string>

#include "../include/Deck.h"

using namespace std;

Deck::Deck()
{
    this -> id = ++deckCounter;
    string Name;
    cin>>Name;
    this -> name = Name;
    this -> deckSize = 25;
}

Deck::~Deck()
{

}

void Deck::addCard(int cardId)
{
    if(this -> deckSize > this -> getSize())
    {
        container.push_back(cardId);
    }
    else
    {
        cout << "You are trying to add more cards than allowed in your deck!" << endl;
    }
}

void Deck::removeCard(int cardId)
{
    int isFound = false;
    for(int i = 0; i< this -> getSize(); i++)
    {
        if(cardId == container[i])
        {
            container.erase(container.begin() + i);
            isFound = true;
            break;
        }
    }
    if(!isFound) cout<<"Card not found in the deck, try another one!"<<endl;
}

int Deck::getId()
{
    return this -> id;
}

int Deck::getSize()
{
    return this -> container.size();
}

string Deck::getName()
{
    return this -> name;
}

std::vector<int> Deck::getDeck()
{
    return this->container;
}
//};
int Deck::deckCounter = 0;


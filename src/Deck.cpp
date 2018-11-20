#include<iostream>
#include<vector>
#include<cstring>//optional - nz dali shte poznae String

#include "Deck.h"
using namespace std;

//class Deck{

/*private:
    std::vector<int> container;//vmesto 100 maximuma karti v kojto shte ima v decka
	static int deckCounter;//broqch na dekovete - zaradi id-to
    int id;
    int containerSize;//broqch na kartite v decka
    int size;//max deck size
    string name;*/

//public:
Deck::Deck() //, size
{
    this->id = deckCounter+1;
    deckCounter++;
    string Name;
    cin>>Name;//Stream.Input();
    this->name = Name;
    this->size = 25;//naprimer
    this->containerSize = 0;
}

Deck::~Deck() {	}

void Deck::addCard(int cardId)
{
    if(size>this->containerSize)
    {
        container.push_back(cardId);
        this->containerSize++;
    }
    else //Moje da se mahne - prosto da ne pravi nichto
    {
        //throw OutOfRangeException();//ExceedingSizeException
        cout<<"You are trying to add more cards than allowed in your deck!"<<endl;//Stream.Output()
    }
}

void Deck::removeCard(int cardId)
{
    int isFound = false;
    for(int i = 0; i<this->containerSize; i++)
    {
        if(cardId==container[i])
        {
            container.erase(container.begin() + i);
            isFound = true;
            break;
        }

    }

    this->containerSize--;
    //Moje da se mahne - prosto da ne pravi nichto
    //if(!isFound)throw CardNotFoundException();
    if(!isFound)
        cout<<"Card not found in the deck, try another one!"<<endl;//Stream.Output()
}

int Deck::getId()
{
    return this->id;
}

int Deck::getSize()
{
    return this->size;
}

string Deck::getName()
{
    return this->name;
}

std::vector<int> Deck::getDeck()
{
    return this->container;
}
//};
int Deck::deckCounter = 0;

/*int main(){
    Deck deck = Deck();
    Deck deck2 = Deck();
    deck.addCard(1);
    cout<<deck.getId()<<endl;
    cout<<deck2.getId()<<endl;
    cout<<deck.getSize()<<endl;
    return 0;
}*/

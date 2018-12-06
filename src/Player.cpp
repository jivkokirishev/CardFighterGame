#include "../include/Player.h"
using namespace std;

Player::Player()
{
    this -> healthPoints = 40;
}

Player::~Player() {	}

void Player::set_name(string name)
{
    this -> name = name;
}

void Player::set_shuffle_deck(DeckStructure shuffleDeck)
{
    CardList* cards = new CardList;
    vector<int> tempDeck = shuffleDeck.getDeck();
    vector<Card*> cardIndexes = cards -> loadCardList();

    srand(time(0));
    int shuffleIndex;
    while(tempDeck.size() > 0)
    {
        shuffleIndex = rand() % tempDeck.size();
        this -> deck.push((cardIndexes.at(tempDeck.at(shuffleIndex))));
        tempDeck.erase(tempDeck.begin() + shuffleIndex);
    }
}

void Player::draw()
{
    if(!deck.empty())
    {
        this -> hand.push_back(deck.top());
        deck.pop();
    }
    else
        setHP(-2);
}

bool Player::setHP(int value)
{
    if(this -> healthPoints + value > 0)
    {
        this -> healthPoints += value;
        return true;
    }
    else
        return false;
}

string Player::get_name()
{
    return this -> name;
}

int Player::get_HP()
{
    return this -> healthPoints;
}

std::vector<Card*> Player::getHand()
{
    return this -> hand;
}

std::vector<Card*> Player::getBoard()
{
    return this -> board;
}

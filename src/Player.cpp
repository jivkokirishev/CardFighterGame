#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "../include/Player.h"
#include "../include/Card.h"
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

void Player::set_shuffle_deck(std::vector<Card> deck)
{
    srand(time(0));
    while(deck.size())
    {
        int rnum = rand() % (deck.size() + 1);
        deck.push_back(deck[rnum]);
        deck.erase(deck.begin() + rnum);
    }
}

void Player::draw()
{
    if(!deck.empty())
    {
        this->hand.push_back(deck.top());
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

std::vector<Card> Player::getHand()
{
    return this -> hand;
}

std::vector<Card> Player::getBoard()
{
    return this -> board;
}
//};
/*int main()
{

    return 0;
}*/

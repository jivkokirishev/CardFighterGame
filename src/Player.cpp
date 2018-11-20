#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Card.h"
using namespace std;
//class Player{

/*private:
    string name;
    std::vector<Card> hand;
    std::stack<Card> deck;
    int healthPoints;
    std::vector<Card> board;
*/
static int Player::randNum(int min, int max)
{
    return rand() % max + min;
}
//public:
Player::Player()
{
    this->healthPoints = 40;
}

Player::~Player() {	}

//moje da e v konstruktor
void Player::set_name(string name)
{
    this->name = name;
}

void Player::set_shuffle_deck(std::vector<Card> dek)
{
    srand(time(0));
    while(dek.size)
    {
        int rnum = randNum(0, dek.size);
        deck.push(dek[rnum]);
        dek.erase(dek.begin() + rnum);
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
        setHP(-2);// - neshto
}

bool Player::setHP(int value)
{
    if(this->healthPoints+value>0)
    {
        this->healthPoints += value;
        return true;
    }
    else
        return false;//throw exception
}

string Player::get_name()
{
    return this->name;
}

int Player::get_HP()
{
    return this->healthPoints;
}

std::vector<Card> Player::getHand()
{
    return this->hand;
}

std::vector<Card> Player::getBoard()
{
    return this->board;
}
//};
/*int main()
{

    return 0;
}*/

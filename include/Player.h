#ifndef DECK_H
#define DECK_H

#include <vector>
#include <stack>
#include "Card.h"

using namespace std;

class Player{
public:
    Player();

    virtual ~Player();

    void set_name(string name);

    void set_shuffle_deck(std::vector<Card> dek);

    void draw();

    bool setHP(int value);

    string get_name();

    int get_HP();

    std::vector<Card> getHand();

    std::vector<Card> getBoard();

private:
    string name;
    std::vector<Card> hand;
    std::stack<Card> deck;
    int healthPoints;
    std::vector<Card> board;

	static int randNum(int min, int max);

};

#endif


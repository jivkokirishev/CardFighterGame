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

    bool setHP(int value);
    void set_name(string name);
    void set_shuffle_deck(std::vector<Card> deck);

    string get_name();
    int get_HP();
    std::vector<Card> getHand();
    std::vector<Card> getBoard();

    void draw();

private:
    string name;
    vector<Card> hand;
    stack<Card> deck;
    int healthPoints;
    vector<Card> board;
};

#endif


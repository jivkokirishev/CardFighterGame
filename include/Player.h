#ifndef DECK_H
#define DECK_H

#include <stack>
#include <string>
#include <cstdlib>
#include <ctime>

#include "CardList.h"
#include "DeckStructure.h"

class Player{
    public:
        Player();
        virtual ~Player();

        bool setHP(int);
        void set_name(string);
        void set_shuffle_deck(DeckStructure);

        string get_name();
        int get_HP();
        vector<Card*> getHand();
        vector<Card*> getBoard();

        void draw();

    private:
        string name;
        vector<Card*> hand;
        vector<Card*> board;
        stack<Card*> deck;
        int healthPoints;
};

#endif


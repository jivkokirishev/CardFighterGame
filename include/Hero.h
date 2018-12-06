#ifndef HERO_H
#define HERO_H

#include "DeckStructure.h"

class Hero {
    private:
        vector<DeckStructure> deckList;
        string name;

    public:
        Hero ();

        void setName(string);

        string getName();

        void createDeck(string);

        vector<DeckStructure> getDecks();
};

#endif // HERO_H

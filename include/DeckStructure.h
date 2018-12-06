#ifndef DECKSTRUCTURE_H
#define DECKSTRUCTURE_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DeckStructure
{
    private:
        vector<int> deckList;   /// Container
        unsigned int id;
        static int deckCounter; /// Counter
        unsigned int maxSize;
        string name;
    public:
        DeckStructure();
        DeckStructure(string);

        void setName(string);

        void addCard(int);
        void removeCard(int);

        unsigned int getId();
        string getName();
        int getMaxSize();
        vector<int> getDeck();
};

#endif // DECKSTRUCTURE_H

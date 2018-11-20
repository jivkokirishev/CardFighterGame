#ifndef DECK_H
#define DECK_H

#include <vector>

using namespace std;
class Deck{

public:
    Deck();

    virtual ~Deck();

    void addCard(int cardId);

    void removeCard(int cardId);

    int getId();

    int getSize();

    string getName();

    std::vector<int> getDeck();

private:
    std::vector<int> container;//vmesto 100 maximuma karti v kojto shte ima v decka
    static int deckCounter;//broqch na dekovete - zaradi id-to
    int id;
    int containerSize;//broqch na kartite v decka
    int size;//max deck size
    string name;

};

#endif

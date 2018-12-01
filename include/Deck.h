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
    std::vector<int> container; /// Vmesto 100 maximuma karti v kojto shte ima v decka
    static int deckCounter;     /// Broqch na dekovete - zaradi id-to
    int id;
    int deckSize;               /// Max deck size
    string name;

};

#endif

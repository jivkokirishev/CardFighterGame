#ifndef CARDLIST_H
#define CARDLIST_H
#define CARD_LIST_SIZE

#include <vector>

#include "Card.h"
#include "Monster.h"
#include "Spell.h"

using namespace std;

class CardList
{
    private:
        vector<Card*> cardList;
    public:
        CardList();
        vector<Card*> loadCardList();
};

#endif // CARDLIST_H

#include "../include/CardList.h"

CardList::CardList()
{
    cardList.push_back(new Monster("Acolyte of Pain", 1, 3, " ", 3, 1));
    cardList.push_back(new Monster("Lab Rat", 0, 3, " ", 5, 1));
    cardList.push_back(new Monster("WW2 Tank", 5, 7, " ", 12, 1));
    cardList.push_back(new Monster("Sewer Rat", 1, 1, " ", 1, 1));
    cardList.push_back(new Monster("Mathematician", 3, 5, " ", 14, 1));
    cardList.push_back(new Monster("Johnny", 2, 1, " ", 3, 0));
    cardList.push_back(new Monster("Blind Archer", 2, 3, " ", 1, 1));
    cardList.push_back(new Monster("Kitty Cat", 5, 5, " ", 5, 1));

    cardList.push_back(new Spell("SPELL: Hatred", 3, 3, "DMG + Freeze", 1, 0));
    cardList.push_back(new Spell("SPELL: Sliced", 1, 3, "DMG + AOE", 0, 1));
    cardList.push_back(new Spell("SPELL: EXECUTE", 100, 7, "The name says it all", 0, 0));
    cardList.push_back(new Spell("SPELL: MASS EXECUTE", 100, 11, "The name says it all", 0, 1));
    cardList.push_back(new Spell("SPELL: Headshot", 5, 5, "DMG", 0, 0));
    cardList.push_back(new Spell("SPELL: Frost Nova", 0, 3, "Freeze + AOE", 1, 1));
    cardList.push_back(new Spell("SPELL: Light Arrow", 2, 1, "DMG", 0, 0));
    cardList.push_back(new Spell("SPELL: Swipe", 3, 3, "DMG + AOE", 0, 1));
}

vector<Card*> CardList::loadCardList()
{
    return this -> cardList;
}

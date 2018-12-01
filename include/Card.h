#ifndef CARD_H
#define CARD_H

#include "CardType.h"
#include <string>


using namespace std;

class Card
{
    public:
        Card();
        Card(unsigned int id, string name, int attack, int manaCost, string description);
        virtual ~Card();

        virtual string ToStream();
        virtual void DealDMG(Card);

        unsigned int GetId();
        string GetName();
        int GetAttack();
        int GetManaCost();
        string GetDescription();

        void SetDescription(string val);
        void SetId(unsigned int val);
        void SetManaCost(int val);
        void SetAttack(int val);
        void SetName(string val);

    private:
        unsigned int id;        //!< Member variable "id"
        string name;            //!< Member variable "name"
        int attack;             //!< Member variable "attack"
        int mana_cost;          //!< Member variable "mana_cost"
        string description;     //!< Member variable "description"
};

#endif // CARD_H

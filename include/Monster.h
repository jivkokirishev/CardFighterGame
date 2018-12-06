#ifndef MONSTER_H
#define MONSTER_H

#include "../include/Card.h"

class Monster : public Card
{
    public:
        Monster();
        Monster(string name, int attack, int manaCost, string description, int healthPoints, int charges);
        virtual ~Monster();

        int GetHealthPoints();
        int GetCharges();

        void SetHealthPoints(int val);
        void SetCharges(int val);
        string ToStream();

    private:
        int healthPoints;   //!< Member variable "healthPoints"
        int charges;        //!< Member variable "charges"
};

#endif // MONSTER_H

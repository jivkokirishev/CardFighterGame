#ifndef SPELL_H
#define SPELL_H

#include "../include/Spell.h"
#include "../include/Monster.h"
#include <string>

using namespace std;

class Spell : public Card
{
    public:
        Spell();
        Spell(unsigned int id, string name, int attack, int manaCost, string description, bool freeze, bool aoe);
        virtual ~Spell();

        bool GetAoe();
        bool GetFreeze();

        void SetFreeze(bool val);
        void SetAoe(bool val);
        string ToStream();

        void DealDMG(Monster);

    private:
        bool freeze;    //!< Member variable "freeze"
        bool aoe;       //!< Member variable "aoe"
};

#endif // SPELL_H

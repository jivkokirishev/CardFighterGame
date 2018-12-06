#include "../include/Spell.h"

Spell::Spell()
{
    //ctor
}

Spell::Spell(string name, int attack, int manaCost, string description, bool freeze, bool aoe)
    : Card(name, attack, manaCost, description)
{
    this -> freeze = freeze;
    this -> aoe = aoe;
}

Spell::~Spell()
{
    //dtor
}

bool Spell::GetFreeze()
{
    return freeze;
}
bool Spell::GetAoe()
{
    return aoe;
}

void Spell::SetFreeze(bool val)
{
    freeze = val;
}

void Spell::SetAoe(bool val)
{
    aoe = val;
}

string Spell::ToStream()
{
    return (string)(this -> GetName() + ", "
                    + to_string(this -> GetAttack()) + " DMG, Mana Cost: "
                    + to_string(this -> GetManaCost()) + ", "
                    + this -> GetDescription()
    );
}

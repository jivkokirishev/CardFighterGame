#include "../include/Spell.h"

Spell::Spell()
{
    //ctor
}

Spell::Spell(unsigned int id, string name, int attack, int manaCost, string description, bool freeze, bool aoe)
    : Card(id, name, attack, manaCost, description)
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

void Spell::DealDMG(Monster enemy)
{
    enemy.SetHealthPoints(enemy.GetHealthPoints() - (this -> GetAttack()));
    if (this -> freeze) enemy.SetCharges(0);
}

string Spell::ToStream()
{
    return (string)(this -> GetName() + ", "
                    + to_string(this -> GetAttack()) + ", "
                    + to_string(this -> GetManaCost()) + ", "
                    + this -> GetDescription()
    );
}

#include "../include/Card.h"

Card::Card(unsigned int id, string name, int attack, int manaCost, string description)
{
    this -> id = id;
    this -> name = name;
    this -> attack = attack;
    this -> mana_cost = manaCost;
}

Card::Card()
{
    //ctor
}

Card::~Card()
{
    //dtor
}

unsigned int Card::GetId()
{
    return id;
}

void Card::SetId(unsigned int val)
{
    id = val;
}

string Card::GetName()
{
    return name;
}

void Card::SetName(string val)
{
    name = val;
}

int Card::GetAttack()
{
    return attack;
}

void Card::SetAttack(int val)
{
    attack = val;
}

int Card::GetManaCost()
{
    return mana_cost;
}

void Card::SetManaCost(int val)
{
    mana_cost = val;
}

string Card::GetDescription()
{
    return description;
}

void Card::SetDescription(string val)
{
    description = val;
}

#include "../include/Card.h"

Card::Card(string name, int attack, int manaCost, string description)
{
    this -> id = ++(this -> cardCounter);
    this -> name = name;
    this -> attack = attack;
    this -> mana_cost = manaCost;
    this -> description = description;
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
    return this -> description;
}

void Card::SetDescription(string val)
{
    description = val;
}

string Card::ToStream()
{
    return "invalid";
}

void Card::SetHealthPoints(int i)
{

}

int Card::GetHealthPoints()
{
    return 1;
}

int Card::cardCounter = 0;

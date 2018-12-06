#include "../include/Monster.h"

Monster::Monster()
{
    //ctor
}
Monster::Monster(string name, int attack, int manaCost, string description, int healthPoints, int charges)
    : Card(name, attack, manaCost, description)
{
    this -> healthPoints = healthPoints;
    this -> charges = charges;
}

Monster::~Monster()
{
    //dtor
}

int Monster::GetHealthPoints()
{
    return healthPoints;
}
int Monster::GetCharges()
{
    return charges;
}

void Monster::SetCharges(int val)
{
    charges = val;
}
void Monster::SetHealthPoints(int val)
{
    healthPoints = val;
}

string Monster::ToStream()
{
    return (string)(this -> GetName() + ", "
                    + to_string(this -> GetAttack()) + " Att. , "
                    + to_string(this -> GetHealthPoints()) + "HP , Mana Cost: "
                    + to_string(this -> GetManaCost())
    );
}

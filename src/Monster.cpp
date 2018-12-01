#include "../include/Monster.h"

Monster::Monster()
{
    //ctor
}
Monster::Monster(unsigned int id, string name, int attack, int manaCost, string description, int healthPoints, int charges)
    : Card(id, name, attack, manaCost, description)
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

void Monster::DealDMG(Monster enemy)
{
    enemy.SetHealthPoints(enemy.GetHealthPoints() - (this -> GetAttack()));
}

string Monster::ToStream()
{
    return (string)(this -> GetName() + ", "
                    + to_string(this -> GetAttack()) + ", "
                    + to_string(this -> GetHealthPoints()) + ", "
                    + to_string(this -> GetManaCost())
    );
}

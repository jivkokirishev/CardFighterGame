#include "Monster.h"

Monster::Monster()
{
    //ctor
}

Monster::Monster(unsigned int id, string name, int attack, int manaCost, string description, int healthPoints, int charges)
    : Card(id, CardType::MONSTER, name, attack, manaCost, description)
{
    this->healthPoints = healthPoints;
    this->charges = charges;
}

Monster::~Monster()
{
    //dtor
}

int Monster::GetHealthPoints()
{
    return healthPoints;
}
/** Set healthPoints
 * \param val New value to set
 */
void Monster::SetHealthPoints(int val)
{
    healthPoints = val;
}

void Monster::DealDamage(int val)
{
    healthPoints -= val;
}

/** Access charges
 * \return The current value of charges
 */
int Monster::GetCharges()
{
    return charges;
}
/** Set charges
 * \param val New value to set
 */
void Monster::SetCharges(int val)
{
    charges = val;
}

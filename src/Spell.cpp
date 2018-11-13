#include "Spell.h"

Spell::Spell()
{
    //ctor
}

Spell::Spell(unsigned int id, string name, int attack, int manaCost, string description, bool freeze, bool aoe)
    : Card(id, CardType::SPELL, name, attack, manaCost, description)
{
    this->freeze = freeze;
    this->aoe = aoe;
}

Spell::~Spell()
{
    //dtor
}



/** Access freeze
 * \return The current value of freeze
 */
bool Spell::GetFreeze()
{
    return freeze;
}
/** Set freeze
 * \param val New value to set
 */
void Spell::SetFreeze(bool val)
{
    freeze = val;
}
/** Access aoe
 * \return The current value of aoe
 */
bool Spell::GetAoe()
{
    return aoe;
}
/** Set aoe
 * \param val New value to set
 */
void Spell::SetAoe(bool val)
{
    aoe = val;
}

#ifndef SPELL_H
#define SPELL_H

#include <Card.h>


class Spell : public Card
{
    public:
        Spell(unsigned int id, string name, int attack, int manaCost, string description, bool freeze, bool aoe);
        /** Default constructor */
        Spell();
        /** Default destructor */
        virtual ~Spell();

        /** Access freeze
         * \return The current value of freeze
         */
        bool GetFreeze();
        /** Set freeze
         * \param val New value to set
         */
        void SetFreeze(bool val);
        /** Access aoe
         * \return The current value of aoe
         */
        bool GetAoe();
        /** Set aoe
         * \param val New value to set
         */
        void SetAoe(bool val);

    protected:

    private:
        bool freeze; //!< Member variable "freeze"
        bool aoe; //!< Member variable "aoe"
};

#endif // SPELL_H

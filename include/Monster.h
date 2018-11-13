#ifndef MONSTER_H
#define MONSTER_H

#include <Card.h>


class Monster : public Card
{
    public:
        /** Default constructor */
        Monster();

        Monster(unsigned int id, string name, int attack, int manaCost, string description, int healthPoints, int charges);

        /** Default destructor */
        virtual ~Monster();

        /** Access healthPoints
         * \return The current value of healthPoints
         */
        int GetHealthPoints();
        /** Set healthPoints
         * \param val New value to set
         */
        void SetHealthPoints(int val);
        /** Access charges
         * \return The current value of charges
         */

        void DealDamage(int val);

        int GetCharges();
        /** Set charges
         * \param val New value to set
         */
        void SetCharges(int val);

    protected:

    private:
        int healthPoints; //!< Member variable "healthPoints"
        int charges; //!< Member variable "charges"
};

#endif // MONSTER_H

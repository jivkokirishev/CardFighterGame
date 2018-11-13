#ifndef CARD_H
#define CARD_H

#include "CardType.h"
#include <string>


using namespace std;

class Card
{
public:
    /** Default constructor */
    Card();

    Card(unsigned int id, CardType type, string name, int attack, int manaCost, string description);

    /** Default destructor */
    virtual ~Card();

    /** Access id
     * \return The current value of id
     */
    unsigned int GetId();
    /** Set id
     * \param val New value to set
     */
    void SetId(unsigned int val);
    /** Access name
     * \return The current value of name
     */
    string GetName();
    /** Set name
     * \param val New value to set
     */
    void SetName(string val);
    /** Access attack
     * \return The current value of attack
     */
    int GetAttack();
    /** Set attack
     * \param val New value to set
     */
    void SetAttack(int val);
    /** Access mana_cost
     * \return The current value of mana_cost
     */
    int GetManaCost();
    /** Set mana_cost
     * \param val New value to set
     */
    void SetManaCost(int val);
    /** Access description
     * \return The current value of description
     */
    string GetDescription();
    /** Set description
     * \param val New value to set
     */
    void SetDescription(string val);

    CardType GetType();

    void SetType(CardType val);

protected:

private:
    unsigned int id; //!< Member variable "id"
    string name; //!< Member variable "name"
    int attack; //!< Member variable "attack"
    int mana_cost; //!< Member variable "mana_cost"
    string description; //!< Member variable "description"
    CardType type;
};

#endif // CARD_H

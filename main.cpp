#include <iostream>
//#include <Card.h>
#include <Spell.h>
#include <Monster.h>
#include <cstring>

using namespace std;

int main()
{
    string name = "Killer";
    string desc = "Something";
    Card *card = new Monster(0, name, 4, 5, desc, 10, 1);
    if(card->GetType() == CardType::MONSTER)
    {
        Monster *mn = dynamic_cast<Monster*>(card);
        mn->DealDamage(2);
        cout << mn->GetHealthPoints()<< endl;
        cout << mn->GetManaCost() << endl;
    }
    cout << card->GetAttack() << endl;
    return 0;
}

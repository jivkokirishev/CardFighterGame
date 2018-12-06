#include "../include/Battle.h"

#define SLEEP_TIME 500

Battle::Battle()
{
    this -> gameOver    = false;
    this -> endTurn     = true;
    this -> turn        = 0;
    this -> played      = false;
    this -> mana        = 0;
    this -> gameLayers  = 0;
}

/// Draw
void Battle::drawHand()
{
    if (this -> turn % 2 == 1)
    {
        for (unsigned i = 0; i < this -> pOne.getHand().size(); i++)
        {
            cout << i + 1 << ". " << this -> pOne.getHand().at(i) -> ToStream() << endl;
        }
    }
    else
    {
        for (unsigned i = 0; i < this -> pTwo.getHand().size(); i++)
        {
            cout << i + 1 << ". " << this -> pTwo.getHand().at(i) -> ToStream() << endl;
        }
    }
}

void Battle::drawBoard()
{
    if (this -> turn % 2 == 1)
    {
        cout << "Enemy board:" << endl;
        for (unsigned i = 0; i < this -> pTwo.getBoard().size(); i++)
        {
            cout << i + 1 << ". " << this -> pTwo.getBoard().at(i) -> ToStream() << endl;
        }
        cout << "---------" << endl;
        cout << "My board:" << endl;
        for (unsigned i = 0; i < this -> pOne.getBoard().size(); i++)
        {
            cout << i + 1 << ". " << this -> pOne.getBoard().at(i) -> ToStream() << endl;
        }
    }
    else
    {
        cout << "Enemy board:" << endl;
        for (unsigned i = 0; i < this -> pOne.getBoard().size(); i++)
        {
            cout << i + 1 << ". " << this -> pOne.getBoard().at(i) -> ToStream() << endl;
        }
        cout << "---------" << endl;
        cout << "My board:" << endl;
        for (unsigned i = 0; i < this -> pTwo.getBoard().size(); i++)
        {
            cout << i + 1 << ". " << this -> pTwo.getBoard().at(i) -> ToStream() << endl;
        }
    }
}

void Battle::drawMana()
{
    if (this -> turn % 2 == 1) cout << "Mana: " << this -> mana << " HP: " << this -> pOne.get_HP() << endl;
    else cout << "Mana: " << this -> mana << " HP: " << this -> pTwo.get_HP() << endl;
}

void Battle::showOptions()
{
    switch(this -> gameLayers)
    {
        case 0:
            cout << "1. Play Card"                  << endl;
            cout << "2. Attack"                     << endl;
            cout << "3. Do Nothing"                 << endl;
            break;
        case 1:
            cout << "1. Summon a Monster"           << endl;
            cout << "2. Play a Spell"               << endl;
            cout << "3. Do Nothing"                 << endl;
            break;
        case 2:
            cout << "1. Choose a Monster"           << endl;
            cout << "2. Do Nothing"                 << endl;
            break;
        case 3:
            cout << "1. Choose an Enemy Monster"    << endl;
            cout << "2. Go Face"                    << endl;
            cout << "3. Do Nothing"                 << endl;
            break;
        case 4:
            cout << "1. Select a Friendly Monster"  << endl;
            cout << "2. Do Nothing"                 << endl;
            break;
        case 5:
            cout << "1. Choose a Spell"             << endl;
            cout << "2. Do Nothing"                 << endl;
            break;
        default:
            break;
     }
}

void Battle::draw()
{
    system("cls");
    this -> drawBoard();
    cout << "---------" << endl;
    cout << "My Hand:"  << endl;
    this -> drawHand();
    cout << "---------" << endl;
    this -> drawMana();
    cout << "---------" << endl;
    this -> showOptions();
}

/// Input
void Battle::analyzeInput()
{
    bool checkValidationOfInput = false;
    cin >> this -> option;
    if (this -> option < 0 && this -> option > 3 && (this -> gameLayers == 0 || this -> gameLayers == 1 || this -> gameLayers == 3))
    {
        checkValidationOfInput = true;
    }
    else if (this -> option < 0 && this -> option > 2 && (this -> gameLayers == 2 || this -> gameLayers == 4 || this -> gameLayers == 5))
    {
        checkValidationOfInput = true;
    }
        switch(this -> gameLayers)
        {
            case 0:
                break;
            case 1:
                this -> option += 3;
                break;
            case 2:
                this -> option += 6;
                break;
            case 3:
                this -> option += 8;
                break;
            case 4:
                this -> option += 11;
                break;
            case 5:
                this -> option += 13;
                break;
            default:
                break;
        }
    if(checkValidationOfInput) this -> option = 0;
}

/// Update
void Battle::nonPlayerAction()
{
    this -> endTurn = false;
    this -> turn++;
    this -> played = false;
    /// Mana Counter
    if (this -> turn <= 8) this -> mana = 3;
    else if (this -> turn <= 12) this -> mana = 5;
    else if (this -> turn <= 14) this -> mana = 7;
    else this -> mana = 11;

    if (this -> turn % 2 == 1) pOne.draw();
    else pTwo.draw();
}

void Battle::handleAction()
{
    bool spell;
    switch(this -> option)
    {
        case 1:
            this -> gameLayers = 1;
            Sleep(SLEEP_TIME);
            break;
        case 2:
            this -> gameLayers = 2;
            spell = false;
            Sleep(SLEEP_TIME);
            break;
        case 3:
            if (!this -> played)
            {
                if (this -> turn % 2 == 1)
                {
                    this -> gameOver = this -> pOne.setHP(-2);
                }
                else
                {
                    this -> gameOver = this -> pTwo.setHP(-2);
                }
            }
            this -> endTurn = true;
            system("cls");
            cout << "Switching Sides..." << endl;
            Sleep(SLEEP_TIME);
            break;
        case 4:
            this -> gameLayers = 4;
            spell = false;
            Sleep(SLEEP_TIME);
            break;
        case 5:
            this -> gameLayers = 5;
            spell = true;
            Sleep(SLEEP_TIME);
            break;
        case 6:
            this -> gameLayers = 0;
            Sleep(SLEEP_TIME);
            break;
        case 7:
            system("cls");
            cout << "Select a Monster from your field: ";
            cin >> marks[0];
            if (this -> turn % 2 == 1)
            {
                if (marks[0] < 0 && marks[0] > this -> pOne.getBoard().size())
                {
                    marks[0] = 0;
                    system("cls");
                    cout << "You don't have a monster on this tile!" << endl;
                }
            }
            else
            {
                if (marks[0] < 0 && marks[0] > this -> pTwo.getBoard().size())
                {
                    marks[0] = 0;
                    system("cls");
                    cout << "You don't have a monster on this tile!" << endl;
                }
            }
            if (marks[0] != 0) this -> gameLayers = 3;
            Sleep(SLEEP_TIME);
            break;
        case 8:
            this -> gameLayers = 0;
            Sleep(SLEEP_TIME);
            break;
        case 9:
            system("cls");
            cout << "Select a Monster from the enemy field: ";
            cin >> marks[1];
            if (this -> turn % 2 == 1)
            {
                if (marks[1] < 0 && marks[1] > this -> pTwo.getBoard().size())
                {
                    marks[1] = 0;
                    system("cls");
                    cout << "Your enemy does not have a monster on this tile!" << endl;
                }
            }
            else
            {
                if (marks[1] < 0 && marks[1] > this -> pOne.getBoard().size())
                {
                    marks[1] = 0;
                    system("cls");
                    cout << "Your enemy does not have a monster on this tile!" << endl;
                }
            }
            if (marks[1] != 0)
            {
                if (spell)
                {
                    if (this -> turn % 2 == 1)
                    {
                        this -> pTwo.getBoard().at(marks[1] - 1) -> SetHealthPoints(-(this -> pOne.getHand().at(marks[0] - 1) -> GetAttack()));
                        if (pTwo.getBoard().at(marks[1] - 1) -> GetHealthPoints() <= 0) pTwo.getBoard().erase(pTwo.getBoard().begin() + marks[1] - 1);
                    }
                    else
                    {
                        this -> pOne.getBoard().at(marks[1] - 1) -> SetHealthPoints(-(this -> pTwo.getHand().at(marks[0]) -> GetAttack()));
                        if (pOne.getBoard().at(marks[1] - 1) -> GetHealthPoints() <= 0) pOne.getBoard().erase(pOne.getBoard().begin() + marks[1] - 1);
                    }
                }
                else
                {
                    this -> pTwo.getBoard().at(marks[1] - 1) -> SetHealthPoints(-(this -> pOne.getBoard().at(marks[0] - 1) -> GetAttack()));
                    this -> pOne.getBoard().at(marks[0] - 1) -> SetHealthPoints(-(this -> pTwo.getBoard().at(marks[1] - 1) -> GetAttack()));

                    if (pTwo.getBoard().at(marks[1] - 1) -> GetHealthPoints() <= 0) pTwo.getBoard().erase(pTwo.getBoard().begin() + marks[1] - 1);
                    if (pOne.getBoard().at(marks[1] - 1) -> GetHealthPoints() <= 0) pOne.getBoard().erase(pOne.getBoard().begin() + marks[1] - 1);
                }
                this -> gameLayers = 0;
            }
            Sleep(SLEEP_TIME);
            break;
        case 10:
            if (spell)
            {
                if (this -> turn % 2 == 1)
                {
                    this -> pTwo.setHP(-(this -> pOne.getHand().at(marks[0] - 1) -> GetAttack()));
                }
                else
                {
                    this -> pOne.setHP(-(this -> pTwo.getHand().at(marks[0] - 1) -> GetAttack()));
                }
            }
            else
            {
                if (this -> turn % 2 == 1)
                {
                    this -> pTwo.setHP(-(this -> pOne.getBoard().at(marks[0] - 1) -> GetAttack()));
                }
                else
                {
                    this -> pOne.setHP(-(this -> pTwo.getBoard().at(marks[0] - 1) -> GetAttack()));
                }
            }
            this -> gameLayers = 0;
            Sleep(SLEEP_TIME);
            break;
        case 11:
            this -> gameLayers = 0;
            Sleep(SLEEP_TIME);
            break;
        case 12:
            system("cls");
            cout << "Select a Monster from your hand: ";
            cin >> marks[0];
            if (this -> turn % 2 == 1)
            {
                if (marks[0] < 0 || marks[0] > this -> pOne.getHand().size())
                {
                    marks[0] = 0;
                    system("cls");
                    cout << "You don't have a monster on this tile!" << endl;
                }
            }
            else
            {
                if (marks[0] < 0 || marks[0] > this -> pTwo.getHand().size())
                {
                    marks[0] = 0;
                    system("cls");
                    cout << "You don't have a monster on this tile!" << endl;
                }
            }
            if (marks[0] != 0)
            {
                if (this -> turn % 2 == 1)
                {
                    this -> pOne.getBoard().push_back(this -> pOne.getHand().at(marks[0] - 1));
                    this -> pOne.getHand().erase(this -> pOne.getHand().begin() + marks[0] - 1);
                }
                else
                {
                    this -> pTwo.getBoard().push_back(this -> pTwo.getHand().at(marks[0] - 1));
                    this -> pTwo.getHand().erase(this -> pTwo.getHand().begin() + marks[0] - 1);
                }
                this -> gameLayers = 0;
            }
            Sleep(SLEEP_TIME);
            break;
        case 13:
            this -> gameLayers = 0;
            Sleep(SLEEP_TIME);
            break;
        case 14:
            system("cls");
            cout << "Select a Spell from your hand: ";
            cin >> marks[0];
            if (this -> turn % 2 == 1)
            {
                if (marks[0] < 0 && marks[0] > this -> pOne.getHand().size())
                {
                    marks[0] = 0;
                    system("cls");
                    cout << "You don't have a Spell on this tile!" << endl;
                }
            }
            else
            {
                if (marks[0] < 0 && marks[0] > this -> pTwo.getHand().size())
                {
                    marks[0] = 0;
                    system("cls");
                    cout << "You don't have a Spell on this tile!" << endl;
                }
            }
            if (marks[0] != 0)
            {
                this -> gameLayers = 3;
            }
            Sleep(SLEEP_TIME);
            break;
        case 15:
            this -> gameLayers = 0;
            Sleep(SLEEP_TIME);
            break;
        default:
            this -> gameLayers = 0;
            Sleep(SLEEP_TIME);
            break;
    }
}

bool Battle::getEndTurn()
{
    return this -> endTurn;
}

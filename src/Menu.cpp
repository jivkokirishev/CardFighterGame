#include "../include/Menu.h"

Menu::Menu()
{
    this -> startBattle = false;
    this -> endGame = false;
    this -> name = "";
    this -> menuLayers = 0;
}

Hero Menu::createHero(string name)
{
    Hero* temp = new Hero();
    temp -> setName(name);
    return *temp;
}

bool Menu::getStart()
{
    return this -> startBattle;
}

bool Menu::getEnd()
{
    return this -> endGame;
}

void Menu::showMenu()
{
    system("cls");
    switch(this -> menuLayers)
    {
        case 0:
            cout << "1. Play" << endl;
            cout << "2. Create a Hero" << endl;
            cout << "3. Create a Deck" << endl;
            cout << "4. Exit" << endl;
            break;

        case 1:
            cout << "Loading Game" << endl;
            break;

        case 2:
            cout << "Enter a Name: ";
            break;

        case 3:
            cout << "Enter a Name of a Hero: ";
            break;
        case 4:
            cout << "Exit Game" << endl;
            break;

        case 5:
            cout << "Enter new Name for a Deck: " << endl;
            break;
        default: break;
    }
}

void Menu::getCommand()
{
    if (this -> menuLayers == 0)
    {
        int command;
        cin >> command;
        this -> menuLayers = command;
    }
    if (this -> menuLayers < 0 && this -> menuLayers > 4)
    {
        this -> menuLayers = 0;
    }
}

void Menu::proceed(vector<Hero>* heroList)
{
    bool checkIfExist;
    switch(this -> menuLayers)
    {
        case 0: break;

        case 1:
            this -> startBattle = true;
            this -> menuLayers = 0;
            Sleep(SLEEP_TIME);
            break;

        case 2:
            checkIfExist = true;
            cin >> this -> name;
            for (unsigned i = 0; i < heroList -> size(); i++)
            {
                if (name == heroList -> at(i).getName())
                {
                    checkIfExist = false;
                    break;
                }
            }
            if (checkIfExist) heroList -> push_back(this -> createHero(name));
            else cout << "This Hero already exists!" << endl;
            Sleep(SLEEP_TIME);
            this -> menuLayers = 0;
            break;

        case 3:
            checkIfExist = false;
            cin >> this -> name;
            for (unsigned i = 0; i < heroList -> size(); i++)
            {
                if (name == heroList -> at(i).getName())
                {
                    this -> index = i;
                    checkIfExist = true;
                    break;
                }
            }
            if (checkIfExist) this -> menuLayers = 5;
            else
            {
                cout << "There is not a Hero with this name!" << endl;
                Sleep(SLEEP_TIME);
                this -> menuLayers = 0;
            }
            break;

        case 4:
            this -> endGame = true;
            Sleep(SLEEP_TIME);
            this -> menuLayers = 0;
            break;

        case 5:
            cin >> this -> name;
            cout << "Error!" << endl;
            cout << heroList -> at(this -> index).getName() << endl;
            cout << "Error!" << endl;
            heroList -> at(index).createDeck(name);
            cout << "Error!" << endl;
            Sleep(SLEEP_TIME);
            this -> menuLayers = 0;
            break;

        default:
            this -> menuLayers = 0;
            break;
    }
}

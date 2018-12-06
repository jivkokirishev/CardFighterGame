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

void Menu::setStart(bool start)
{
    this -> startBattle = start;
}

void Menu::setEnd(bool ending)
{
    this -> endGame = ending;
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
        while (!cin.good())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
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
            do
            {
                this -> name = "";
                cin.ignore();
                getline(cin, this -> name);
                if (this -> name.size() > 20)
                {
                    cout << "You are trying to enter a name with more than 20 characters!" << endl;
                    Sleep(SLEEP_TIME);
                    system("cls");
                    cout << "Enter a Name: ";
                }
            }
            while (this -> name.size() < 0 || this -> name.size() > 20);
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
            do
            {
                this -> name = "";
                cin.ignore();
                getline(cin, this -> name);
                if (this -> name.size() > 20)
                {
                    cout << "You are trying to enter a name with more than 20 characters!" << endl;
                    Sleep(SLEEP_TIME);
                    system("cls");
                    cout << "Enter a Name of a Hero: ";
                }
            }
            while (this -> name.size() < 0 || this -> name.size() > 20);
            for (unsigned i = 0; i < heroList -> size(); i++)
            {
                if (this -> name == heroList -> at(i).getName())
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
            heroList -> at(index).createDeck(name);
            Sleep(SLEEP_TIME);
            this -> menuLayers = 0;
            break;

        default:
            this -> menuLayers = 0;
            break;
    }
}

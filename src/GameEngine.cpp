#include "../include/GameEngine.h"

GameEngine::GameEngine()
{
    this -> state = 1;
    this -> menu.setHeroList(this -> heroList);
}

void GameEngine::setState(int state)
{
    this -> state = state;
}

void GameEngine::stateManager()
{
    Hero hOne, hTwo;

    /**/
    string nameOfHero;
    string nameOfDeck;
    unsigned indexOne, indexTwo;
    bool preCheck, check;

    while(this -> state != 0)
    {
        switch(this -> state)
        {
            case 0:
                cout << "Goodbye!" << endl;
                break;
            case 1:
                this -> setState(menu.menuLoop());
                this -> heroList = menu.getHeroList();
                break;
            case 2:
                preCheck = false, check = false;
                do
                {
                    system("cls");
                    cout << "Enter Hero One: ";
                    cin >> nameOfHero;
                    Sleep(SLEEP_TIME);
                    for (unsigned i = 0; i < this -> heroList.size() || !preCheck; i++)
                    {
                        if (nameOfHero == this -> heroList.at(i).getName())
                        {
                            hOne = (this -> heroList.at(i));
                            system("cls");
                            cout << "Enter Name of a Deck: ";
                            cin >> nameOfDeck;
                            Sleep(SLEEP_TIME);
                            for (unsigned j = 0; j < this -> heroList.at(i).getDecks().size() || !preCheck; j++)
                            {
                                if(nameOfDeck == this -> heroList.at(i).getDecks().at(j).getName())
                                {
                                    indexOne = j;
                                    preCheck = true;
                                }
                            }
                        }
                    }
                    if(!preCheck)
                    {
                        system("cls");
                        cout << "There is not  such a Hero or Deck: ";
                        Sleep(SLEEP_TIME);
                    }
                }
                while(!preCheck);
                do
                {
                    system("cls");
                    cout << "Enter Hero Two: ";
                    cin >> nameOfHero;
                    Sleep(SLEEP_TIME);
                    for (unsigned i = 0; i < this -> heroList.size() || !check; i++)
                    {
                        if (nameOfHero == this -> heroList.at(i).getName())
                        {
                            hTwo = (this -> heroList.at(i));
                            system("cls");
                            cout << "Enter Name of a Deck: ";
                            cin >> nameOfDeck;
                            Sleep(SLEEP_TIME);
                            for (unsigned j = 0; j < this -> heroList.at(i).getDecks().size() || !check; j++)
                            {
                                if(nameOfDeck == this -> heroList.at(i).getDecks().at(j).getName())
                                {
                                    indexTwo = j;
                                    check = true;
                                }
                            }
                        }
                    }
                    if(!check)
                    {
                        system("cls");
                        cout << "There is not  such a Hero or Deck" << endl;
                        Sleep(SLEEP_TIME);
                    }
                    else if (hOne.getName() == hTwo.getName())
                    {
                        system("cls");
                        cout << "You cannot select two identical Heroes!";
                        Sleep(SLEEP_TIME);
                    }
                }
                while(!check || (hOne.getName() == hTwo.getName()));
                /**cout << "Error: " << (this -> heroList.size()) << endl;
                hOne = (this -> heroList.at(0));
                hTwo = (this -> heroList.at(1));
                cout << "Error" << endl;*/
                this -> battle.gameLoop(hOne, indexOne, hTwo, indexTwo);
                break;
            default:
                system("cls");
                cout << "Break!" << endl;
                Sleep(SLEEP_TIME);
                this -> setState(0);
                break;
        }
    }
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include "Level1.h"
#include "Menu.h"
#include "Player.h"
#include "Goblin.h"
#include "Level2.h"
using namespace std;

Level1::Level1()
{

}

void Level1::loadLevel()
{
    setPlayer();
    printStory();
    startLevel();

}

void Level1::startLevel()
{
    player->drawHud();
    spawnGoblins();
    console();
}

void Level1::printStory()
{
    system("cls");
    cout << "The story begins a long time ago when a warrior named " << player->getName() << endl;
    cout << "wakes up in the deepest dungeon in the middle of nowhere.\n";
    cout << "He looks around and sees himself lying in a long hall,\n";
    cout << "and can not remember how he got there.\n";
    system("pause");
    system("cls");
    cout << "Alongside the hall torches are attached on the wall.\n";
    cout << "As he grabs one and his journey begins.\n";
    cout << "After a minute of walking he sees a dead man holding a wooden sword\n";
    cout << "laying on the floor.\n";
    cout << player->getName() << " decides to pick it up.\n";
    system("pause");
    system("cls");
}

void Level1::console()
{
    string cmd = "nothing";
    int RNG;
    int potionRNG;
    srand(time(0));

    while(player->getHealth()>0)
    {
        cout << "Type 'move' to move forward or 'wait' to recover.\n";

        while(cmd!="move" && cmd!="wait")
        {
            cout << ">"; getline(cin, cmd);
        }

        if(cmd=="move")
        {
            cout << "Now walking...\n";
            Sleep(3000);
            cout << player->getName() << " moved few steps forward and ";

            RNG = 1+(rand()%3);
            potionRNG = 1+(rand()%5);


            if(RNG==1 || RNG==2 && potionRNG!=2)
            {
                cout << "nothing happened.\n";
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                player->drawHud();
            }
            else if(RNG==2 && potionRNG==2)
            {
                cout << "found a health potion!\n";
                cout << "-------------------------------------------------\n";
                player->setPotions(player->getPotions()+1);
                system("pause");
                system("cls");
                player->drawHud();
            }
            else if(RNG==3)
            {
                if(numOfGoblins>0)
                {
                    cout << "encountered a Goblin!\n";
                    cout << "-------------------------------------------------\n";
                    system("pause");
                    system("cls");
                    battle();
                }
                else // if there are no goblins left in the dungeon found an exit and end the level.
                {
                    cout << "found a light!\n";
                    endLevel();
                }

            }

            cmd = "nothing";
        }

        if(cmd=="wait")
        {
            cout << "Now waiting...\n";
            Sleep(5000);
            cout << "While " << player->getName() << " was waiting ";
            RNG = 1+(rand()%6);

            if(RNG==1 || RNG==2 || RNG==3 || RNG==4 || RNG==5)
            {
                if(player->getHealth()<120)
                {
                    cout << "health recovered.\n";
                    player->setHealth(player->getHealth()+5);
                }
                else
                {
                    cout << "health recovered to maximum.\n";
                }

                system("pause");
                system("cls");
                player->drawHud();
            }
            else if(RNG==6)
            {
                cout << "encountered a goblin.\n";
                system("pause");
                system("cls");
                battle();
            }


            cmd = "nothing";
        }
    }
    system("cls");
    cout << "Oh no! You have died!\n";
    system("pause");
    Menu objMenu;
    objMenu.showMenu();

}


void Level1::setPlayer()
{
    string name = "Player";
    player->setHealth(100);
    player->setArmor(0);
    player->setDamage(10);
    player->setPotions(0);

    cout << "Enter your name: ";
    getline(cin, name);
    if(name=="")
    {
        name = "Player";
    }
    player->setName(name);
}

void Level1::setGoblin()
{
    if(numOfGoblins>0)
    {
        goblin->setGoblinStats();
    }
}

void Level1::spawnGoblins()
{
    srand(time(0));
    numOfGoblins = 2+(rand()%(3-2+1));

    goblin->setGoblinStats();
}

void Level1::drawEncounterHud()
{
    cout << "| " << player->getName() << "                   | Enemy: " << goblin->getName() << endl;
    cout << "| Health: " << player->getHealth() << "            | Health: " << goblin->getHealth() << endl;
    cout << "| Armor: " << player->getArmor() << "               | Armor: 0" << endl;
    cout << "| Damage: " << player->getDamage() << "             | Damage: " << goblin->getDamage() << endl;
    cout << "| Health potions: " << player->getPotions() << "      |" << endl;
    cout << "---------------------------------------------------------------\n";
}

void Level1::battle()
{
    string command;
    int RNG;
    srand(time(0));

    drawEncounterHud();
    while(goblin->getHealth()>0)
    {
        cout << "Type: \n";
        cout << "'attack' to attack the enemy.\n";
        cout << "'block' to block enemy attacks. \n";
        cout << "'potion' to use health potion. \n";

        while(command!="attack" && command!="block" && command!="potion")
        {
            cout << ">";
            getline(cin, command);
        }

        if(command=="attack")
        {
            cout << "Now attacking...\n";
            Sleep(2000);
            goblin->setHealth(goblin->getHealth()-player->getDamage());
            cout << "Goblins health -" << player->getDamage() << endl;
            cout << "-------------------------------------------------\n";
            system("pause");
            system("cls");
            drawEncounterHud();

            if(goblin->getHealth()>0)
            {
                cout << "Goblin attacking...\n";
                Sleep(2000);
                cout << player->getName() << " health -" << goblin->getDamage() << endl;
                player->setHealth(player->getHealth()-goblin->getDamage());
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                drawEncounterHud();
            }

        }
        else if(command=="block")
        {
            cout << "Now blocking...\n";
            Sleep(2000);

            RNG = 1+(rand()%3);

            if(RNG==1 || RNG==2)
            {
                cout << "Block successful.\n";
                player->setHealth(player->getHealth()+5);
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                drawEncounterHud();
            }
            else if(RNG==3)
            {
                cout << "Block failed.\n";
                cout << player->getName() << " health -" << goblin->getDamage() << endl;
                player->setHealth(player->getHealth()-goblin->getDamage());
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                drawEncounterHud();
            }
        }
        else if(command=="potion")
        {
            if(player->getPotions()>0)
            {
                player->setPotions(player->getPotions()-1);
                cout << "Now using health potion...\n";
                Sleep(2000);
                cout << player->getName() << " healed for 30.\n";
                player->setHealth(player->getHealth()+30);
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                drawEncounterHud();
            }
            else
            {
                cout << "You don't have any potions left!\n";
                system("pause");
                system("cls");
                drawEncounterHud();
            }

        }

        command = "nothing";
    }
    cout << "Goblin was killed.\n";
    cout << "Drops: nothing.\n";
    cout << "-------------------------------------------------\n";
    numOfGoblins -=1;
    setGoblin();
    system("pause");
    system("cls");
    player->drawHud();
}

void Level1::endLevel()
{
    srand(time(0));
    int RNG;

    cout << player->getName() << " was following the light...\n";
    Sleep(5000);
    cout << "But he realized that the light he was following was not leading \n";
    cout << "to an exit but to a higher level of the dungeon. \n";
    cout << "This dungeon looked even scarier than the one before. \n";
    cout << "He went forward because this was the only way he could go. \n";
    system("pause");
    system("cls");
    cout << "Congratulations you finished the first level of the dungeon! \n";

    RNG = 1+(rand()%6);
    if(RNG==6)
    {
        cout << "Reward: leather armor!\n";
        player->setArmor(5);
    }
    else
    {
        cout << "Reward: nothing.\n";
    }
    playerName = player->getName();
    playerHealth = player->getHealth();
    playerArmor = player->getArmor();
    playerDamage = player->getDamage();

    Level2 objLevel2;
    objLevel2.loadLevel();
}

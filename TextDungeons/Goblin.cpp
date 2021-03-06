#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Level.h"
#include "Level1.h"
#include "Menu.h"
#include "Player.h"
#include "Goblin.h"
#include "Level2.h"
using namespace std;

Goblin::Goblin()
{
    goblinName = "Goblin";
}

void Goblin::setGoblinStats()
{
    int num = 0;
    srand(time(0));
    num = 1+(rand()%3);
    if(num==1)
    {
        goblinHealth = 30;
        goblinDamage = 5;
    }

    if(num==2)
    {
        goblinHealth = 35;
        goblinDamage = 6;
    }

    if(num==3)
    {
        goblinHealth = 40;
        goblinDamage = 7;
    }

}

void Goblin::setHealth(int h)
{
    goblinHealth = h;
}

string Goblin::getName(){ return goblinName; }
int Goblin::getHealth() { return goblinHealth; }
int Goblin::getDamage() { return goblinDamage; }


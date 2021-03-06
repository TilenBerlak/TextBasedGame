#ifndef LEVEL1_H
#define LEVEL1_H

#include "Player.h"
#include "Goblin.h"
#include "Level2.h"
using namespace std;

class Level1
{
    public:
        Level1();
        void loadLevel();
        void printStory();
        void startLevel();
        void setPlayer();
        void spawnGoblins();
        void console();
        void drawEncounterHud();
        void battle();
        void setGoblin();
        void endLevel();

    protected:
        string playerName;
        int playerHealth;
        int playerArmor;
        int playerDamage;

    private:
        int numOfGoblins;

    Player objPlayer;
    Player *player = &objPlayer;

    Goblin objGoblin;
    Goblin *goblin = &objGoblin;


};

#endif // LEVEL1_H

#ifndef LEVEL2_H
#define LEVEL2_H

#include "Player.h"
#include "Goblin.h"
#include "Level1.h"
using namespace std;


class Level2
{
    public:
        Level2();
        void loadLevel();
        void startLevel();
        void setPlayer();
        void spawnGoblins();
        void console();
        void drawEncounterHud();
        void battle();
        void setGoblin();
        void endLevel();

    protected:
    private:
};

#endif // LEVEL2_H

#ifndef GOBLIN_H
#define GOBLIN_H

#include <string>
using namespace std;


class Goblin
{
    public:
        Goblin();
        void setGoblinStats();
        void setHealth(int h);


        string getName();
        int getDamage();
        int getHealth();
    protected:

    private:
        string goblinName;
        int goblinHealth;
        int goblinDamage;
};

#endif // GOBLIN_H

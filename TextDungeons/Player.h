#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
    public:
        Player();
        string getName();
        int getHealth();
        int getArmor();
        int getDamage();
        int getPotions();

        void setName(string n);
        void setHealth(int h);
        void setArmor(int a);
        void setDamage(int d);
        void setPotions(int p);

        void drawHud();

    protected:
        int playerHealth;
        int playerArmor;
        int playerDamage;
        int playerPotions;

    private:
        string playerName;

};

#endif // PLAYER_H

#ifndef MENU_H
#define MENU_H

#include <string>
#include "Player.h"
#include "Level1.h"
using namespace std;

class Menu
{
    public:
        Menu();
        void showMenu();
        void showCredits();
    protected:
    private:
        string menuControl;
        Level1 objLevel1;
        Level1 *level1 = &objLevel1;
};

#endif // MENU_H

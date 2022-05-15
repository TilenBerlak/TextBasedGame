#include "Hud.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Enemy.h"
#include "Level.h"
#include "Level1.h"
#include "Menu.h"
#include "Player.h"
using namespace std;

Hud::Hud()
{

}

void Hud::drawHud()
{
cout << Player->getName();
}

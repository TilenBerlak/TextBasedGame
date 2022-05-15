#include <iostream>
#include <stdlib.h>
#include <string>
#include "Level1.h"
#include "Menu.h"
#include "Player.h"
#include "Goblin.h"
#include "Level2.h"
using namespace std;

Player::Player()
{

}

string Player::getName() { return playerName; }
int Player::getHealth() { return playerHealth; }
int Player::getArmor() { return playerArmor; }
int Player::getDamage() { return playerDamage; }
int Player::getPotions() { return playerPotions; }

void Player::setName(string n) { playerName = n; }
void Player::setHealth(int h) { playerHealth = h; }
void Player::setArmor(int a) { playerArmor = a; }
void Player::setDamage(int d) { playerDamage = d; }
void Player::setPotions(int p) { playerPotions = p; }


void Player::drawHud()
{
    cout << "| " << getName() << "                   | Enemy: " << endl;
    cout << "| Health: " << getHealth() << "            | Health: " << endl;
    cout << "| Armor: " << getArmor() << "               | Armor: " << endl;
    cout << "| Damage: " << getDamage() << "             | Damage: " << endl;
    cout << "| Health potions: " << getPotions() << "      |" << endl;
    cout << "---------------------------------------------------------------\n";
}

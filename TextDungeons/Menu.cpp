#include <iostream>
#include <stdlib.h>
#include <string>
#include "Level1.h"
#include "Menu.h"
#include "Player.h"
#include "Goblin.h"
using namespace std;

Menu::Menu()
{

}

void Menu::showMenu()
{
    system("cls");
    cout << "                              TextDungeons" << endl;
    cout << endl;
    cout << "Type following number to: \n";
    cout << "1. Start \n";
    cout << "2. Credits \n";
    cout << "3. Exit \n";
    cout << "> ";
    getline(cin,menuControl);
    while(menuControl!="1" && menuControl!="2" && menuControl!="3")
    {
        cout << "Invalid command \n";
        getline(cin,menuControl);
    }

    if(menuControl=="1")
    {
         //start game
         system("cls");
         level1->loadLevel();
    }

    if(menuControl=="2")
    {
        showCredits();
    }

    if(menuControl=="3")
    {
        //exit game
    }

}

void Menu::showCredits()
{
    system("cls");
    cout << "TextDungeons\n";
    cout << "Written by Tilen Berlak \n";
    cout << "Software used: \n";
    cout << "Code::Blocks \n";
    cout << "Programmed in C++ \n";
    cout << "February 2015 \n";

    system("pause");
    showMenu();
}

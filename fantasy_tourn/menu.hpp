/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This the header file for the menu function, and its helpers.
*********************************************************************/
#ifndef  MENU_HPP
#define MENU_HPP
#include <iostream>
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;

void menu();
void fight(Character** attacker, Character** defender);
bool isDead(Character* ch1, Character* ch2);
void chooseCharacters(Character** ch1, Character** ch2);
void printStats(Character* attacker, Character* defender);
void pressEnter();

#endif


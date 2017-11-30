/*********************************************************************
** Program name:Fantasy Tournament
** Author:Trevor Rollins
** Date:11/19/2017
** Description:This is the header file for the tournament class.  This class
is used to create a battle between two teams of characters.  It allows the 
user to pick the size of the teams, the characters that make up each team,
and the stats for each fight.
*********************************************************************/
#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP
#include "Queue.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "inputValidation.hpp"
using std::cin;

class Tournament
{
private:
	int team1Points, team2Points;
	Queue lineup1;
	Queue lineup2;
	Queue losers1;
	Queue losers2;
	void displayScore();
	void clearLineups();
	int battle();
	void play();
	void createLineup(int size, int team);
	Character* pickCharacter();
public:
	
	void menu();
	
	Tournament();
	~Tournament();
};
#endif


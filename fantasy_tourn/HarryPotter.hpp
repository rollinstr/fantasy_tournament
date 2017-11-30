/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This the header file for HaryyPotter class.  The HarryPotter class
is a derivation of Character.  It is used has public attack and defend
functions that can be used to battle other charactes.
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;


class HarryPotter :
	public Character
{
private:
	bool hogwartsUsed;
public:
	virtual int attack();
	virtual void defend(int damage);
	HarryPotter();
	~HarryPotter();
};
#endif



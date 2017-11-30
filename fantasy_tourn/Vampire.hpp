/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This the header file for Vampire class.  The Vampire class
is a derivation of Character.  It is used has public attack and defend
functions that can be used to battle other charactes.
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;


class Vampire :
	public Character
{
public:
	virtual int attack();
	virtual void defend(int damage);
	Vampire();
	~Vampire();
};
#endif


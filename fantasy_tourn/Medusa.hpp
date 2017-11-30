/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This the header file for Medusa class.  The Medusa class
is a derivation of Character.  It is used has public attack and defend 
functions that can be used to battle other charactes.
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;


class Medusa :
	public Character
{
public:
	virtual int attack();
	virtual void defend(int damage);
	Medusa();
	~Medusa();
};
#endif


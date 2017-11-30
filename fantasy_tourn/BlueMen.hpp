/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This the header file for BlueMen class.  The BlueMen class
is a derivation of Character.  It is used has public attack and defend
functions that can be used to battle other charactes.
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"
#include <iostream>
using std::cout;
using std::endl;


class BlueMen :
	public Character
{
public:
	virtual int attack();
	virtual void defend(int damage);
	BlueMen();
	~BlueMen();
};
#endif

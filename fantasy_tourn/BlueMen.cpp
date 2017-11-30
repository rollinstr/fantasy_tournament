/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This is the implementation file for the BlueMen class.
*********************************************************************/
#include "BlueMen.hpp"
/*********************************************************************
** Function Purpose:This is the default constructor for BlueMen.  It sets
armor to 3 and strength points to 12. It also initializes the type to "Blue Men"
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
BlueMen::BlueMen() : Character(3, 12)
{
	type = "Blue Men";
}
/*********************************************************************
** Function Purpose:This function produces an attack value based on
random dice rolls.
** Arguments:None
** Restrictions:None
** Return Value:Int representing the attack value
*********************************************************************/
int BlueMen::attack()
{
	int attack = (dieRoll(10) + dieRoll(10));
	attackRoll = attack;
	return attack;
}
/*********************************************************************
** Function Purpose:This function produces an defend value based on
random dice rolls. Changes the number of dice to be rolled based off of
the strength points of the BlueMen
** Arguments:Int damage of attacker
** Restrictions:None
** Return Value:None
*********************************************************************/
void BlueMen::defend(int damage)
{
	if (getStrength() <= 4)
	{
		defenseRoll = dieRoll(6);
	}
	else if (getStrength() <= 8)
	{
		defenseRoll = (dieRoll(6) + dieRoll(6));
	}
	else
	{
		defenseRoll = (dieRoll(6) + dieRoll(6) + dieRoll(6));
	}
	damageTaken = (damage - getDefenseRoll() - getArmor());
	if (damageTaken < 0)
	{
		damageTaken = 0;
	}
	decStrength(getDamageTaken());
}

BlueMen::~BlueMen()
{
}

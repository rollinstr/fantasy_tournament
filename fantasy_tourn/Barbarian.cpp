/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This is the implementation file for the Barbarian class.
*********************************************************************/
#include "Barbarian.hpp"
/*********************************************************************
** Function Purpose:This is the default constructor for Barbarian.  It sets
armor to 0 and strength points to 12. It also initializes the type to "Barbarian"
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Barbarian::Barbarian() : Character(0, 12)
{
	type = "Barbarian";
}
/*********************************************************************
** Function Purpose:This function produces an attack value based on
random dice rolls.
** Arguments:None
** Restrictions:None
** Return Value:Int representing the attack value
*********************************************************************/
int Barbarian::attack()
{
	int attack = (dieRoll(6) + dieRoll(6));
	attackRoll = attack;
	return attack;
}
/*********************************************************************
** Function Purpose:This function produces an defend value based on
random dice rolls. 
** Arguments:Int damage of attacker
** Restrictions:None
** Return Value:None
*********************************************************************/
void Barbarian::defend(int damage)
{
	defenseRoll = (dieRoll(6) + dieRoll(6));
	damageTaken = (damage - getDefenseRoll() - getArmor());
	if (damageTaken < 0)
	{
		damageTaken = 0;
	}
	decStrength(getDamageTaken());
}

Barbarian::~Barbarian()
{
}

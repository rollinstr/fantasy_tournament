/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This is the implementation file for the Medusa class.
*********************************************************************/
#include "Medusa.hpp"
/*********************************************************************
** Function Purpose:This is the default constructor for Medusa.  It sets
armor to 3 and strength points to 8. It also initializes the type to "Medusa"
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Medusa::Medusa() : Character(3, 8)
{
	type = "Medusa";
}
/*********************************************************************
** Function Purpose:This function produces an attack value based on
random dice rolls. If medusa rolls 12, glare is activated and the attack
value becomes 1000
** Arguments:None
** Restrictions:None
** Return Value:Int representing the attack value
*********************************************************************/
int Medusa::attack()
{
	int attack = (dieRoll(6) + dieRoll(6));
	if (attack == 12)
	{
		attack = 1000;
		cout << "Medusa used glare." << endl;
	}
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
void Medusa::defend(int damage)
{
	defenseRoll = (dieRoll(6));
	damageTaken = (damage - getDefenseRoll() - getArmor());
	if (damageTaken < 0)
	{
		damageTaken = 0;
	}
	decStrength(getDamageTaken());
}

Medusa::~Medusa()
{
}

/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This is the implementation file for the Vampire class.
*********************************************************************/
#include "Vampire.hpp"
/*********************************************************************
** Function Purpose:This is the default constructor for vampire.  It sets
armor to 1 and strength points to 18. It also initializes the type to "Vampire"
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Vampire::Vampire() : Character(1, 18)
{
	type = "Vampire";
}
/*********************************************************************
** Function Purpose:This function produces an attack value based on 
random dice rolls.
** Arguments:None
** Restrictions:None
** Return Value:Int representing the attack value
*********************************************************************/
int Vampire::attack()
{
	int attack = dieRoll(12);
	attackRoll = attack;
	return attack;
}
/*********************************************************************
** Function Purpose:This function produces an defend value based on 
random dice rolls. It also gives a 50% chance for charm. It then 
calculates the damage taken.
** Arguments:Int damage of attacker
** Restrictions:None
** Return Value:None
*********************************************************************/
void Vampire::defend(int damage)
{
	bool charm = (bool)(rand() % 2);
	if (charm)
	{
		cout << "Vampire used charm, no damage was taken." << endl;
		defenseRoll = 1000;
		damageTaken = 0;
	}
	else if (!charm)
	{
		defenseRoll = dieRoll(6);
		damageTaken = (damage - getDefenseRoll() - getArmor());
		if (damageTaken < 0)
		{
			damageTaken = 0;
		}
		decStrength(getDamageTaken());
	}
}



Vampire::~Vampire()
{
}

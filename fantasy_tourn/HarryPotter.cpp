/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This is the implementation file for the HarryPotter class.
*********************************************************************/
#include "HarryPotter.hpp"
/*********************************************************************
** Function Purpose:This is the default constructor for HarryPotter.  It sets
armor to 0 and strength points to 10. It also initializes the type to 
"Harry Potter". It also initializes hogwartsUsed to false.
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
HarryPotter::HarryPotter() : Character(0, 10)
{
	type = "Harry Potter";
	hogwartsUsed = false;
}
/*********************************************************************
** Function Purpose:This function produces an attack value based on
random dice rolls.
** Arguments:None
** Restrictions:None
** Return Value:Int representing the attack value
*********************************************************************/
int HarryPotter::attack()
{
	int attack = (dieRoll(6) + dieRoll(6));
	attackRoll = attack;
	return attack;
}
/*********************************************************************
** Function Purpose:This function produces an defend value based on
random dice rolls. If strength points<=0 and hogwartsUsed=false, then 
Hogwarts is activated and strength points are set to 20.
** Arguments:Int damage of attacker
** Restrictions:None
** Return Value:None
*********************************************************************/
void HarryPotter::defend(int damage)
{
	defenseRoll = (dieRoll(6)+dieRoll(6));
	damageTaken = (damage - getDefenseRoll() - getArmor());
	if (damageTaken < 0)
	{
		damageTaken = 0;
	}
	decStrength(getDamageTaken());
	if ((getStrength() <= 0) && (!hogwartsUsed))
	{
		setStrength(20);
		hogwartsUsed = true;
		cout << "Harry Potter used Hogwarts." << endl;
	}
}

HarryPotter::~HarryPotter()
{
}

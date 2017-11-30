/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This is the implementation file for the Character class.
*********************************************************************/
#include "Character.hpp"
/*********************************************************************
** Function Purpose:This is the constructor for Character.  It initilizes
armor and strength point values
** Arguments:int for armor value, and int for strength value
** Restrictions:None
** Return Value:None
*********************************************************************/
Character::Character(int armor, int strength)
{
	setArmor(armor);
	setStrength(strength);
}
/*********************************************************************
** Function Purpose:This is a setter for mArmor
** Arguments:int for value to be set
** Restrictions:None
** Return Value:None
*********************************************************************/
void Character::setArmor(int armor)
{
	mArmor = armor;
}
/*********************************************************************
** Function Purpose:This is a setter for mStrengthPoints
** Arguments:int for value to be set
** Restrictions:None
** Return Value:None
*********************************************************************/
void Character::setStrength(int strength)
{
	mStrengthPoints = strength;
}
/*********************************************************************
** Function Purpose:This decrements mStrengthPoints be the argument value
** Arguments:int to decrement strength points by
** Restrictions:None
** Return Value:None
*********************************************************************/
void Character::decStrength(int strengthDec)
{
	mStrengthPoints -= strengthDec;
}
/*********************************************************************
** Function Purpose:Getter function for mArmor
** Arguments:None
** Restrictions:None
** Return Value:Int representing Armor
*********************************************************************/
int Character::getArmor() const
{
	return mArmor;
}
/*********************************************************************
** Function Purpose:Getter function for mStrengthPoints
** Arguments:None
** Restrictions:None
** Return Value:Int representing strength points
*********************************************************************/
int Character::getStrength() const
{
	return mStrengthPoints;
}
/*********************************************************************
** Function Purpose:Getter function for attackRoll
** Arguments:None
** Restrictions:None
** Return Value:Int representing attackRoll
*********************************************************************/
int Character::getAttackRoll() const
{
	return attackRoll;
}
/*********************************************************************
** Function Purpose:Getter function for defenseRoll
** Arguments:None
** Restrictions:None
** Return Value:Int representing defenseRoll
*********************************************************************/
int Character::getDefenseRoll() const
{
	return defenseRoll;
}
/*********************************************************************
** Function Purpose:Getter function for damageTaken
** Arguments:None
** Restrictions:None
** Return Value:Int representing damageTaken
*********************************************************************/
int Character::getDamageTaken() const
{
	return damageTaken;
}
/*********************************************************************
** Function Purpose:Getter function for type
** Arguments:None
** Restrictions:None
** Return Value:string representing type
*********************************************************************/
string Character::getType() const
{
	return type;
}
/*********************************************************************
** Function Purpose:Simulates a single die by returning random int between
1 and the number of sides.
** Arguments:Number of sides on the die 
** Restrictions:None
** Return Value:Int representing roll value
*********************************************************************/
int Character::dieRoll(int sides)
{
	return ((rand() % sides) + 1);
}

void Character::recovery()
{
	double recovery = (dieRoll(5)*.1);
	mStrengthPoints += (int)(recovery*mStrengthPoints);
}

bool Character::isDead()
{
	return (mStrengthPoints <= 0);
}

void Character::setName(string nm)
{
	name = nm;
}

string Character::getName() const
{
	return name;
}

Character::~Character()
{
}

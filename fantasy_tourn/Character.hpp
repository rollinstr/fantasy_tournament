/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This the header file for Character class.  This class is
abstract, and provides inheritance of member variables and functions for 
derived classes.  It has member variables for armor, strength points, type,
defense roll, damage taken, and attack roll.  It also provides getter
and setter fucntions that can ge inherited
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <cstdlib>
#include <string>
using std::string;


class Character
{
protected:
	string name;
	int mArmor;
	int mStrengthPoints;
	int defenseRoll;
	int attackRoll;
	int damageTaken;
	string type;

	void setArmor(int armor);
	void setStrength(int strength);
	void decStrength(int strengthDec);
	int dieRoll(int sides);
	
public:
	void setName(string nm);
	string getName() const;
	bool isDead();
	void recovery();
	int getAttackRoll() const;
	int getDefenseRoll() const;
	int getDamageTaken() const;
	int getArmor() const;
	int getStrength() const;
	string getType() const;
	virtual int attack() = 0;
	virtual void defend(int damage) = 0;
	Character(int armor, int strength);
	virtual ~Character();
};
#endif


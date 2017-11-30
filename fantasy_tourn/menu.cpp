/*********************************************************************
** Program name:Fantasy Combat
** Author:Trevor Rollins
** Date:11/5/2017
** Description:This is the implementation file for the menu functions.
*********************************************************************/
#include "menu.hpp"
#include <ctime>
/*********************************************************************
** Function Purpose:This ties all the helper functions together in a loop
and allows the loop to continue until the game is over.  It then asks the 
user if they'd like toplay again.
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void menu()
{
	srand((unsigned)time(0));
	int endGame=1;
	do
	{
		Character* ch1=nullptr;
		Character* ch2=nullptr;
		chooseCharacters(&ch1, &ch2);
		bool endFight = false;
		int round = 1;
		do
		{
			cout << "Round #" << round << endl;

			fight(&ch1, &ch2);
			printStats(ch1, ch2);
			endFight = isDead(ch1, ch2);

			if (!endFight)
			{
				fight(&ch2, &ch1);
				printStats(ch2, ch1);
				pressEnter();
				endFight = isDead(ch1, ch2);
			}
			
			round++;

		} while (!endFight);
		delete ch1;
		delete ch2;
		cout << "1. Play Again" << endl;
		cout << "2. Exit the game" << endl;
		endGame = intValidator(1, 2);

	} while (endGame != 2);
}
/*********************************************************************
** Function Purpose:This presents a list of character options to the user
and creates a 2 new characters based off of the user choice.
** Arguments:It takes 2 &Character* so that it can modify the addresses 
of the pointers declared in the menu function.
** Restrictions:None
** Return Value:None
*********************************************************************/
void chooseCharacters(Character** ch1, Character** ch2)
{
	Character** characters[2] = { ch1, ch2 };
	enum characterChoices {eVampire=1, eBarbarian, eBlueMen, eMedusa, eHarryPotter };
	characterChoices choice;

	cout << "You will need to select two characters to fight each other." << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "1. Vampire" << endl;
		cout << "2. Barbarian" << endl;
		cout << "3. Blue Men" << endl;
		cout << "4. Medusa" << endl;
		cout << "5. Harry Potter" << endl;
		cout << "Please select character " << (i+1) << ": ";
		choice = (characterChoices)intValidator(1, 5);
		

		switch (choice)
		{
		case eVampire:
			*characters[i] = new Vampire;
			break;
		case eBarbarian:
			*characters[i] = new Barbarian;
			break;
		case eBlueMen:
			*characters[i] = new BlueMen;
			break;
		case eMedusa:
			*characters[i] = new Medusa;
			break;
		case eHarryPotter:
			*characters[i] = new HarryPotter;
			break;
		}

	}
}
/*********************************************************************
** Function Purpose:This function gets the attack of one character, and 
passes it into the defend function of the other character.
** Arguments:2 &Character* 
** Restrictions:The arguments can't be nullptr
** Return Value:None
*********************************************************************/
void fight(Character** attacker, Character** defender)
{
	int attack = (*attacker)->attack();
	(*defender)->defend(attack);
}

bool isDead(Character* ch1, Character* ch2)
{
	if (ch1->getStrength() <= 0)
	{
		cout << ch2->getType() << " won the fight!" << endl;
		return true;
	}
	else if (ch2->getStrength() <= 0)
	{
		cout << ch1->getType() << " won the fight!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
/*********************************************************************
** Function Purpose:This function prints all of the stats of one attack
and defend(half a round).
** Arguments:Pointer to the attacker and defender Characters
** Restrictions:None
** Return Value:None
*********************************************************************/
void printStats(Character* attacker, Character* defender)
{
	cout << endl;
	cout << "Attacker Type: " << attacker->getType() << endl;
	cout << "Defender Type: " << defender->getType() << ", Armor: " << defender->getArmor()
		<< ", Strength Points: " << (defender->getStrength()+defender->getDamageTaken()) << endl;
	cout << "Attacker Roll: " << attacker->getAttackRoll() << endl;
	cout << "Defender Roll: " << defender->getDefenseRoll() << endl;
	cout << "Damage Taken: " << attacker->getAttackRoll() << "(attack roll) - " << defender->getArmor() << "(armor) - "
		<< defender->getDefenseRoll() << "(defense roll) = " << defender->getDamageTaken() << endl;
	cout << "New Defender Strength Points: " << defender->getStrength() << endl;
	cout << endl;

}
/*********************************************************************
** Function Purpose:This function requires the user to press enter to
continue.
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void pressEnter()
{
	string temp;
	cout << "Press enter to continue the game.";
	getline(cin, temp);
}
/*********************************************************************
** Program name:Fantasy Tournament
** Author:Trevor Rollins
** Date:11/19/2017
** Description:This is the implementation file for the Tournament class
*********************************************************************/
#include "Tournament.hpp"
/*********************************************************************
** Function Purpose:This is the default constructor for the tournament
class.  It sets both teams point values to 0
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
Tournament::Tournament()
{
	team1Points = 0;
	team2Points = 0;
}
/*********************************************************************
** Function Purpose:This function lets the user pick the characters of the lineups
by calling the pickCharacter() to fill each lineup.
** Arguments:Size of the lineup, team number
** Restrictions:None
** Return Value:None
*********************************************************************/
void Tournament::createLineup(int size, int team)
{
	
	Character* newCharacter;
	string name;
	cout << "Choose " << size << " fighters for team " <<team<<":"<< endl;
	for (int i = 0; i < size; i++)
	{
		newCharacter = pickCharacter();
		cout << "What is this fighter's name? ";
		getline(cin, name);
		newCharacter->setName(name);
		if (team == 1)
		{
			lineup1.addBack(newCharacter);
		}
		else
		{
			lineup2.addBack(newCharacter);
		}
		
	}
}
/*********************************************************************
** Function Purpose:This allows the user to pick a character type, and
then allocates a new character of that type
** Arguments:None
** Restrictions:None
** Return Value:Character* pointing to new character created
*********************************************************************/
Character* Tournament::pickCharacter()
{
	enum characterChoices { eVampire = 1, eBarbarian, eBlueMen, eMedusa, eHarryPotter };
	characterChoices choice;
	Character* newCharacter=nullptr;

	cout << "Please select a character type:" << endl;
	
	cout << "1. Vampire" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Blue Men" << endl;
	cout << "4. Medusa" << endl;
	cout << "5. Harry Potter" << endl;
	choice = (characterChoices)intValidator(1, 5);

	switch (choice)
	{
	case eVampire:
		newCharacter = new Vampire;
		break;
	case eBarbarian:
		newCharacter = new Barbarian;
		break;
	case eBlueMen:
		newCharacter = new BlueMen;
		break;
	case eMedusa:
		newCharacter = new Medusa;
		break;
	case eHarryPotter:
		newCharacter = new HarryPotter;
		break;
	}
	return newCharacter;
}
/*********************************************************************
** Function Purpose:This allows the fighters at the front of each lineup to 
fight. THe loser is moved ot the loser queue, and the winner is moved to 
the back of its lineup queue
** Arguments:None
** Restrictions:None
** Return Value:The number of the losign team's member
*********************************************************************/
int Tournament::battle()
{
	Character* chr1 = lineup1.getFront();
	Character* chr2 = lineup2.getFront();

	while ((!chr1->isDead()) && (!chr2->isDead()))
	{
		int attack = chr1->attack();
		chr2->defend(attack);

		if (!chr2->isDead())
		{
			int attack = chr2->attack();
			chr1->defend(attack);
		}
	}
	if (chr1->isDead())
	{
		Character* loser = lineup1.popFront();
		losers1.addBack(loser);
		chr2->recovery();
		lineup2.frontToBack();
		team2Points++;
		team1Points--;
		return 1;
	}
	else if (chr2->isDead())
	{
		Character* loser = lineup2.popFront();
		losers2.addBack(loser);
		chr1->recovery();
		lineup1.frontToBack();
		team1Points++;
		team2Points--;
		return 2;
	}
	else
	{
		cout << "Error with battle." << endl;
		return 0;
	}
}
/*********************************************************************
** Function Purpose:This prints the score of the game, and allows the user
to view the names in the losers queue
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void Tournament::displayScore()
{
	Queue* losers;
	cout << "Team 1: " << team1Points << " points" << endl;
	cout << "Team 2: " << team2Points << " points" << endl;

	if (team1Points > team2Points)
	{
		cout << "Team 1 wins!!" << endl;
		losers = &losers2;
	}
	else if (team1Points < team2Points)
	{
		cout << "Team 2 wins!!" << endl;
		losers = &losers1;
	}
	else
	{
		cout << "It's a tie!" << endl;
		losers = nullptr;
	}
	if(losers!=nullptr)
	{
		cout << "Would you like to see the losers (Y/N)?";
		char answer = charValidator('Y', 'N');
		if (answer == 'Y')
		{
			losers->printQueue();
		}
	}
}
/*********************************************************************
** Function Purpose:This clears the contents of all queues and sets the point
values back to 0
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void Tournament::clearLineups()
{
	lineup1.emptyQueue();
	lineup2.emptyQueue();
	losers1.emptyQueue();
	losers2.emptyQueue();
	team1Points = 0;
	team2Points = 0;
}
/*********************************************************************
** Function Purpose:This lets the user pick the size of the teams, lets the
two temas battle unitl one of the lineups is empty which ends the game.
** Arguments:None
** Restrictions:None
** Return Value:None
*********************************************************************/
void Tournament::play()
{
	int lineupSize;
	cout << "How many fighters are on each team? ";
	lineupSize = intValidator(1);
	createLineup(lineupSize, 1);
	createLineup(lineupSize, 2);
	int round = 1;
	int loser;

	while ((!lineup1.isEmpty()) && (!lineup2.isEmpty()))
	{
		string ch1Name = lineup1.getFront()->getName();
		string ch2Name = lineup2.getFront()->getName();
		string ch1Type = lineup1.getFront()->getType();
		string ch2Type = lineup2.getFront()->getType();

		cout << "Round " << round << ": Team 1 " << ch1Name << "(" << ch1Type << ")  vs. Team 2 " 
			<< ch2Name << "(" << ch2Type << ")" << endl;
			
		loser = battle();

		if (loser == 1)
		{
			cout << ch2Name << " won!" << endl;
			
		}
		else if (loser == 2)
		{
			cout << ch1Name << " won!" << endl;
		}
		round++;
	}
	displayScore();
	clearLineups();
}

/*********************************************************************
** Function Purpose:This is a menu that allows the user to interact with
the options of the tournament class
** Arguments:
** Restrictions:
** Return Value:
*********************************************************************/
void Tournament::menu()
{
	int choice;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
	choice = intValidator(1, 2);
	if (choice == 1)
	{
		do
		{
			play();

			cout << "1. Play" << endl;
			cout << "2. Exit" << endl;
			choice = intValidator(1, 2);

		} while (choice != 2);
	}
}

Tournament::~Tournament()
{
}

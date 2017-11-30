/******************************************************************************
* Authors:     Trevor Rollins
* Date:        10/27/2017
* Title:       Group Project
* Description: Defines the inputValidation class
******************************************************************************/

#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::getline;
using std::endl;


/*********************************************************************
** Function Purpose:This function uses a loop to prompt the user for input
                    until the input passes through the called checkInt function.
** Arguments:It takes a low and high int value to make an inclusive range
             of valid input. It also has defualt arguments of a minimum and
			 maximum value for low high respectively.
** Restrictions:None
** Return Value:It returns an int that has passed all validation checks.
*********************************************************************/
int intValidator(int low, int high)
{
	bool isValidated = false;
	string strInput;
	int output;

	do {
		//takes user input as a string
		
		getline(cin, strInput);
		//stringstream concept from cplusplus.com
		stringstream ssInput(strInput);


		isValidated = checkInt(&ssInput, output, low, high);
	} while (!isValidated);
	
	return output;
}


/*********************************************************************
** Function Purpose:This function uses a loop to prompt the user for input
                    until the input passes through the called checkDouble function.
** Arguments:It takes a low and high double value to make an inclusive range
             of valid input. It also has defualt arguments of a minimum and
			 maximum value for low high respectively.
** Restrictions:None
** Return Value:It returns a double that has passed all validation checks.
*********************************************************************/
double doubleValidator(double low, double high)
{
	bool isValidated = false;
	string strInput;
	double output;

	do {
		
		getline(cin, strInput);
		stringstream ssInput(strInput);


		isValidated = checkDouble(&ssInput, output, low, high);


	} while (!isValidated);
	
	return output;
}


/*********************************************************************
** Function Purpose:To check to see if the char inputted by the user matches
                    allowable chars.
** Arguments:Two chars that are possible for validation
** Restrictions:None
** Return Value:It will return a valid char input
*********************************************************************/
char charValidator(char char1, char char2, char char3, char char4, char char5)
{
	bool isValidated = false;
	string strInput;
	char output;

	do {
		
		getline(cin, strInput);


		isValidated = checkChar(strInput, output, char1, char2, char3, char4, char5);


	} while (!isValidated);
	
	return output;
}

/*********************************************************************
** Function Purpose:To check to see if the strings inputted by the user matches
                    up to 5 allowable strings.  It will reprompt user, if input
					is not valid.
** Arguments:5 strings that are possible for validation
** Restrictions:None
** Return Value:It will return a valid string input
*********************************************************************/
string stringValidator(string str1, string str2, string str3, string str4, string str5)
{
	bool isValidated = false;
	string strInput;
	string output="";

	do {

		getline(cin, strInput);


		isValidated = checkString(strInput, output, str1, str2, str3, str4, str5);


	} while (!isValidated);

	return output;
}

/*********************************************************************
** Function Purpose:This checks the input for certain requirements: being
                    an int, within the allowed range (if specified).
** Arguments:It takes a pointer to a stringstream, a reference to the int
             output, and a low and high int range.
** Restrictions:The stringstream must alrerady have the string to be outputted
                within it.
** Return Value:It returns a bool; true if the input is valid, false if its not.
*********************************************************************/
bool checkInt(stringstream* ssInput, int& output, int low, int high)
{
	int input;
	string testStr = ssInput->str();

	for (size_t i = 0; i < testStr.size(); i++)
	{
		if (!((testStr[i] <= '9') && (testStr[i] >= '0')))
		{
			if (!(testStr[i] == '-'))
			{
				cout << "Please enter an integer." << endl;
				return false;
			}
		}
	}


	if (*ssInput >> input)
	{
		
			if ((input <= high) && (input >= low))
			{
				output = input;
				return true;
			}
			else
			{
				cout << "Please enter an integer between " << low
					<< " and " << high << "." << endl;
				return false;
			}
	}

	else if (!(*ssInput >> input))
	{
		cout << "Please enter an integer." << endl;
		return false;
	}
	else
	{
		cout << "Error with SS to input" << endl;
		return false;
	}
}

/*********************************************************************
** Function Purpose:This checks the input for certain requirements: being
                    an double, within the allowed range (if specified).
** Arguments:It takes a pointer to a stringstream, a reference to the double
             output, and a low and high int range.
** Restrictions:The stringstream must alrerady have the string to be outputted
                 within it.
** Return Value:It returns a bool; true if the input is valid, false if its not.
*********************************************************************/
bool checkDouble(stringstream*
	ssInput, double& output, double low, double high)
{
	double input;

	if (*ssInput >> input)
	{
		if ((input <= high) && (input >= low))
		{
			output = input;
			return true;
		}
		else
		{
			cout << "Please enter a number between " << low
				<< " and " << high << "." << endl;
			return false;
		}
	}

	else if (!(*ssInput >> input))
	{
		cout << "Please enter a number." << endl;
		return false;
	}
	else
	{
		cout << "Error with SS to input" << endl;
		return false;
	}
}

/*********************************************************************
** Function Purpose:This will check the validity of the user's char input
                   for: being only one char, matching the preset allowable
				   chars.
** Arguments:A string that the pruduct of the user input, a refernce to the
             char output, and the allowable chars.
** Restrictions:None
** Return Value:It returns a bool; true if the input is valid, false if its not.
*********************************************************************/
bool checkChar(string input, char& output, char char1, char char2, char char3, char char4, char char5)
{
	char inputChar = toupper(input[0]);
	char testChars[5] = { char1, char2, char3, char4, char5 };
	string wrongInput;

	if (input.size() > 1)
	{
		cout << "Please enter only one character." << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < 5;i++)
		{
			if ((inputChar == testChars[i]) && (testChars[i] != ' '))
			{
				output = inputChar;
				return true;
			}
		}
	}
	wrongInput.append("Please enter one of: ");

	for (int i = 0; i < 5; i++)
	{
		if (testChars[i] != ' ')
		{
			wrongInput.push_back(testChars[i]);
			wrongInput.append(", ");
		}
	}
		wrongInput.pop_back();
		wrongInput.pop_back();
		wrongInput.push_back('.');
		cout << wrongInput << endl;
		return false;

}
/*********************************************************************
** Function Purpose:This will check the validity of the user's string input
                    for matching the preset allowable strings.
** Arguments:A string that the pruduct of the user input, a refernce to the
             string output, and the 5 allowable strings.
** Restrictions:None
** Return Value:It returns a bool; true if the input is valid, false if its not.
*********************************************************************/
bool checkString(string strInput, string& output, string str1, string str2, string str3, string str4, string str5)
{
	string wrongInput;
	string testStrings[5] = { str1, str2, str3, str4, str5 };
	output = "";
	for (size_t i = 0; i < strInput.size(); i++)
	{
		output.push_back(tolower(strInput[i]));
	}

	for (int i = 0; i < 5;i++)
	{
		if ((output == testStrings[i]) && (testStrings[i] != ""))
		{
			output = testStrings[i];
			return true;
		}
	}
	wrongInput.append("Please enter one of: ");

	for (int i = 0; i < 5; i++)
	{
		if (testStrings[i] != "")
		{
			wrongInput.append(testStrings[i]);
			wrongInput.append(", ");
		}
	}
	wrongInput.pop_back();
	wrongInput.pop_back();
	wrongInput.push_back('.');
	cout << wrongInput << endl;
	return false;

}
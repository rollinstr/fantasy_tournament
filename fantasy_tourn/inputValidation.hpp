/******************************************************************************
* Authors:     Trevor Rollins
* Date:        10/27/2017
* Title:       Group Project
* Description: header file for the input validation functions.
******************************************************************************/

#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>
#include <sstream>
#include <iostream>
#include <limits>

using std::string;
using std::stringstream;

int intValidator(int low = std::numeric_limits<int>::min(), int high = std::numeric_limits<int>::max());
double doubleValidator(double low= std::numeric_limits<double>::min(), double high= std::numeric_limits<double>::max());
char charValidator(char char1, char char2 = ' ', char char3 = ' ', char char4 = ' ', char char5 = ' ');
string stringValidator(string str1, string str2="", string str3="", string str4="", string str5="");

bool checkInt(stringstream* ssInput, int& intOutput, int low, int high);
bool checkDouble(stringstream* ssInput, double& doubleOutput, double low, double high);
bool checkChar(string input, char& output, char char1, char char2, char char3, char char4, char char5);
bool checkString(string strInput, string& output, string str1, string str2, string str3, string str4, string str5);

#endif

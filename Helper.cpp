#pragma once
#include "Helper.h"
#include <iostream>
using namespace std;

int getValuePick()
{
valuePick:

	int value;

	cin >> value;

	if (cin.fail())
	{
		cout << "Incorrect input, try again please..." << endl;
		cout << "> ";
		cin.clear();
		cin.ignore(32767, '\n');
		goto valuePick;
	}

	switch (value)
	{
	case 1: return value;
	case 2: return value;
	case 3: return value;
	default:
		cout << "Incorrect input, try again please..." << endl;
		cout << "> ";
		goto valuePick;
		break;
	}

	cin.clear();
	cin.ignore(32767, '\n');
	return value;
}

int getValueMainMenu()
{
	int value;
	cin >> value;

	if (cin.fail() || value < 1 || value > 5)
	{
		cout << "Incorrect input, try again please..." << endl;
		cout << "> ";
		cin.clear();
		cin.ignore(32767, '\n');
	}

	return value;
}

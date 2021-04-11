#pragma once


bool haveNumber(string line)
{
	int i = 0;

	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			return true;
		}
		i++;
	}

	return false;
}

int getParameter()
{
valuePick:
	int value;

	cin >> value;

	if (cin.fail())
	{
		cout << "Incorrect input, try again please..." << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto valuePick;
	}

	return value;
}

int getValuePick()
{
valuePick:

	int value;

	cin >> value;

	if (cin.fail())
	{
		cout << "Incorrect input, try again please..." << endl;
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
		goto valuePick;
		break;
	}

	return value;
}

int getValueMainMenu()
{
	int value;
	cin >> value;

	if (cin.fail() || value < 1 || value > 5)
	{
		cout << "Incorrect input, try again please..." << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}

	return value;
}

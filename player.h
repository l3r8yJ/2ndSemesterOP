// класс игрока

#pragma once
#include <string>
#include <iostream>

using namespace std;

class player
{
	string name, team;									// поля
	int numOfGoals, numOfGoalAssists, penaltyTime;
public:													//сеттеры геттеры, конструктор не использовал

	int intSet()
	{
	valuePick:

		int value;
		cout << "> ";
		cin >> value;

		if (cin.fail())
		{
			cout << "Incorrect input, try again please..." << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			goto valuePick;
		}
		else if (value < 0)
		{
			cout << "Wrong value! " << endl;
			goto valuePick;
		}
		else
		{
			return value;
		}
	}

	void setTeam(string t)
	{
		team = t;
	}

	string getTeam()
	{
		return team;
	}

	void setName()
	{
		bool correct = true;

	setting:
		string line;
		cout << "Enter a name: " << endl;
		cout << "> ";
		cin >> line;

		if (correct)
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line.length() < 3)
				{
					cout << "Have length lower then 3!" << endl;
					cout << "> ";
					correct = false;
				}

				if (line[i] == ' ')
				{
					cout << "Have space!" << endl;
					cout << "> ";
					correct = false;
				}

				if (line[i] >= '0' && line[i] <= '9')
				{
					cout << "Have number!" << endl;
					cout << "> ";
					correct = false;
				}

				if (line[i] == '!' || line[i] == '@' || line[i] == '#' || line[i] == '$' || line[i] == '%' || line[i] == '^' || line[i] == '&' || line[i] == '*' || line[i] == '(' || line[i] == ')' || line[i] == ':' || line[i] == '?' || line[i] == '"' || line[i] == '_' || line[i] == '-' || line[i] == '+' || line[i] == '[' || line[i] == ']' || line[i] == '{' || line[i] == '}' || line[i] == ',' || line[i] == '.' || line[i] == '<' || line[i] == '>' || line[i] == '~' || line[i] == '`' || line[i] == '|' || line[i] == '/')
				{
					cout << "Have incorrect character -> " << line[i] << endl;
					cout << "> ";
					correct = false;
				}

				if (!correct)
				{
					goto setting;
				}
			}
		}

		line[0] = toupper(line[0]);
		name = line;
	}

	string getName()
	{
		return name;
	}

	void setNumOfGoals()
	{
		cout << "Enter number of goals: " << endl;
		numOfGoals = intSet();
	}

	int getNumOfGoals()
	{
		return numOfGoals;
	}

	void setNumOfGoalAssists()
	{
		cout << "Enter number of assists: " << endl;
		numOfGoalAssists = intSet();
	}

	int getNumOfGoalAssists()
	{
		return numOfGoalAssists;
	}

	void setPenaltyTime()
	{
		cout << "Enter player's penalty time: " << endl;
		penaltyTime = intSet();
	}

	int getPenaltyTime()
	{
		return penaltyTime;
	}

	string autoTeam(int pickOne)               // определение команды
	{
		string team;

		if (pickOne == 1)
		{
			team = "Dinamo";
		}
		else if (pickOne == 2)
		{
			team = "Spartak";
		}
		else
		{
			team = "\0";
		}

		return team;
	}

	void fillPlayer(int pickOne)		// функция создания игрока, принимает интовую переменную чтобы определиться с командой автоматически
	{
		setName();
		setTeam(autoTeam(pickOne));
		setNumOfGoals();
		setNumOfGoalAssists();
		setPenaltyTime();
	}
};

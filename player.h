// ����� ������

#pragma once
#include <string>

using namespace std;

class player
{
	string name, team;									// ���� 
	int numOfGoals, numOfGoalAssists, penaltyTime;
public:													//������� �������, ����������� �� ����������� 

	void setTeam(string t)
	{
		team = t;
	}

	string getTeam()
	{
		return team;
	}

	void setName(string n)
	{
		name = n;
	}

	string getName()
	{
		return name;
	}

	void setNumOfGoals(int n)
	{
		numOfGoals = n;
	}

	int getNumOfGoals()
	{
		return numOfGoals;
	}

	void setNumOfGoalAssists(int n)
	{
		numOfGoalAssists = n;
	}

	int getNumOfGoalAssists()
	{
		return numOfGoalAssists;
	}

	void setPenaltyTime(int t)
	{
		penaltyTime = t;
	}

	int getPenaltyTime()
	{
		return penaltyTime;
	}
};

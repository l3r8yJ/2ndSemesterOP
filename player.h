// ����� ������

#pragma once
#include <string>
#include <iostream>

using namespace std;

class player
{
	string name, team;									// ����
	int numOfGoals, numOfGoalAssists, penaltyTime;
public:													//������� �������, ����������� �� �����������

	int intSet();

	void setTeam(string);

	string getTeam();

	void setName();

	string getName();

	void setNumOfGoals();

	int getNumOfGoals();

	void setNumOfGoalAssists();

	int getNumOfGoalAssists();

	void setPenaltyTime();

	int getPenaltyTime();

	string autoTeam(int);              // ����������� �������
	
	void fillPlayer(int);		// ������� �������� ������, ��������� ������� ���������� ����� ������������ � �������� �������������

};

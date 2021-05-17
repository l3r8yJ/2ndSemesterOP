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

	string autoTeam(int);              // определение команды
	
	void fillPlayer(int);		// функция создания игрока, принимает интовую переменную чтобы определиться с командой автоматически

};

#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "playerList.h"

using namespace std;

player createPlayer(int pickOne)
{
	player thisPlayer;

	string name, team;
	int goal, asist, penalty;

	cout << "Enter the name of player: " << endl;
	cin >> name;

	if (pickOne == 1)
	{
		team = "Dinamo";
	}
	else if(pickOne == 2)
	{
		team == "Spartak";
	}
	else
	{
		team = "\0";
	}

goalPoint:
	cout << "Enter the number of goals that player did: " << endl;
	cin >> goal;

	if (goal < 0)
	{
		cout << "Wrong value! " << endl;
		goto goalPoint;
	}

asistPoint:
	cout << "Enter the number of asists that player did: " << endl;
	cin >> asist;

	if (asist < 0)
	{
		cout << "Wrong value! " << endl;
		goto asistPoint;
	}

penaltyPoint:
	cout << "Enter player's penalty time: " << endl;
	cin >> penalty;

	if (penalty < 0)
	{
		cout << "Wrong value! " << endl;
		goto penaltyPoint;
	}

	thisPlayer.setName(name);
	thisPlayer.setTeam(team);
	thisPlayer.setNumOfGoals(goal);
	thisPlayer.setPenaltyTime(penalty);

	return thisPlayer;
}

int main()
{
	bool processLive = true;

	playerList dinamoList;
	playerList spartakList;
	playerList bothTeamList;

	while (processLive)
	{
	mainMenu:

		system("cls");

		cout << "What do you want to do? " << endl;
		cout << "1. Add player to team. " << endl;
		cout << "2. Show list of players. " << endl;
		cout << "3. Create file with players. " << endl;
		cout << "4. Create file with best players from both teams. " << endl;
		cout << "5. Exit..." << endl;

		int choose;
		cin >> choose;

		switch (choose)
		{
		case 1:
		pickPointOne:

			system("cls");

			cout << "Which team's player you wanna add? " << endl;
			cout << "1. Dinamo. " << endl;
			cout << "2. Spartak. " << endl;
			cout << "3. Back..." << endl;

			int pickOne;
			cin >> pickOne;

			if (pickOne == 1)
			{
				player dinamoPlayer = createPlayer(pickOne);
				dinamoList.addPlayer(dinamoPlayer);
				bothTeamList.addPlayer(dinamoPlayer);
				goto pickPointOne;
			}

			if (pickOne == 2)
			{
				player spartakPlayer = createPlayer(pickOne);
				spartakList.addPlayer(spartakPlayer);
				bothTeamList.addPlayer(spartakPlayer);
				goto pickPointOne;
			}

			if (pickOne == 3)
			{
				goto mainMenu;
			}

		case 2:
		pickPointTwo:

			system("cls");

			cout << "Which team's player list you wanna see? " << endl;
			cout << "1. Dinamo. " << endl;
			cout << "2. Spartak. " << endl;
			cout << "3. Back..." << endl;

			int pickTwo;
			cin >> pickTwo;

			if (pickTwo == 1)
			{

				if (dinamoList.getSize() == 0)
				{
					cout << "There's no players in team..." << endl;
					system("pause");
					goto pickPointTwo;
				}

				dinamoList.showList();
				system("pause");
				goto pickPointTwo;
			}

			if (pickTwo == 2)
			{

				if (spartakList.getSize() == 0)
				{
					cout << "There's no players in team..." << endl;
					system("pause");
					goto pickPointTwo;
				}

				spartakList.showList();
				system("pause");
				goto pickPointTwo;
			}

			if (pickTwo == 3)
			{
				goto mainMenu;
			}

		case 3:
		pickPointThree:

			system("cls");

			cout << "Which team's file you wanna to create? " << endl;
			cout << "1. Dinamo. " << endl;
			cout << "2. Spartak. " << endl;
			cout << "3. Back..." << endl;

			int pickThree;
			cin >> pickThree;

			if (pickThree == 1)
			{
				dinamoList.createFile("dinamoDB.txt");
				system("pause");
				goto pickPointThree;
			}

			if (pickThree == 2)
			{
				spartakList.createFile("spartakDB.txt");
				system("pause");
				goto pickPointThree;
			}

			if (pickThree == 3)
			{
				goto mainMenu;
			}

		case 4:

			bothTeamList.sort();
			bothTeamList.createFile("bestplayersDB.txt");
			system("pause");
			goto mainMenu;

		case 5:
			processLive = false;
			break;

		default:
			break;
		}
	}

	return 0;
}
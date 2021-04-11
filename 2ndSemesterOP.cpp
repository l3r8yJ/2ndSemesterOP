#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "playerList.h"
#include "Helper.h"

using namespace std;

player createPlayer(int pickOne)
{
	player thisPlayer;

	string name, team;
	int goal, assist, penalty;

namePoint:
	cout << "Enter the name of player: " << endl;
	cout << "> ";
	cin >> name;

	name[0] = toupper(name[0]);

	if (haveNumber(name))
	{
		cout << "Name can't contain numbers, enter name again please." << endl;
		goto namePoint;
	}

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

goalPoint:
	cout << "Enter the number of goals that player did: " << endl;
	cout << "> ";

	goal = getParameter();

	if (goal < 0)
	{
		cout << "Wrong value! " << endl;
		goto goalPoint;
	}

asistPoint:
	cout << "Enter the number of asists that player did: " << endl;
	cout << "> ";
	assist = getParameter();

	if (assist < 0)
	{
		cout << "Wrong value! " << endl;
		assist = NULL;
		goto asistPoint;
	}

penaltyPoint:
	cout << "Enter player's penalty time: " << endl;
	cout << "> ";
	penalty = getParameter();

	if (penalty < 0)
	{
		cout << "Wrong value! " << endl;
		goto penaltyPoint;
	}

	thisPlayer.setName(name);
	thisPlayer.setTeam(team);
	thisPlayer.setNumOfGoals(goal);
	thisPlayer.setNumOfGoalAssists(assist);
	thisPlayer.setPenaltyTime(penalty);

	return thisPlayer;
}

int main()
{
	bool processLive = true;

	playerList dinamoList;
	playerList spartakList;
	playerList bothTeamList;

	int pickOne, pickTwo, pickThree, choose;

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
		cout << "> ";

		choose = getValueMainMenu();

		switch (choose)
		{
		case 1:
		pickPointOne:

			system("cls");

			cout << "Which team's player you wanna add? " << endl;
			cout << "1. Dinamo. " << endl;
			cout << "2. Spartak. " << endl;
			cout << "3. Back..." << endl;
			cout << "> ";

			pickOne = getValuePick();

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
			cout << "> ";

			pickTwo = getValuePick();

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
			cout << "> ";

			pickThree = getValuePick();

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

			if (bothTeamList.getSize() > 0 && bothTeamList.getSize() >= 6)
			{
				bothTeamList.sortEfficiency();
				bothTeamList.createFileWithSixBestPlayers("bestplayersDB.txt");
				system("pause");
				goto mainMenu;
			}
			else if (bothTeamList.getSize() < 6)
			{
				cout << "Number of players is not enough!" << endl;
				system("pause");
				goto mainMenu;
			}

		case 5:

			processLive = false;
			break;

		default:
			goto mainMenu;
		}
	}

	return 0;
}
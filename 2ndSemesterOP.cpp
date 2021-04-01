#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "playerList.h"

using namespace std;

player createPlayer()
{
	player thisPlayer;

	string name, team;
	int goal, asist, penalty;

	cout << "Enter the name of player: " << endl;
	cin >> name;

	cout << "Enter the player's team: " << endl;
	cin >> team;

	cout << "Enter the number of goals that player did: " << endl;
	cin >> goal;

	cout << "Enter the number of asists that player did: " << endl;
	cin >> asist;

	cout << "Enter player's penalty time: " << endl;
	cin >> penalty;

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
	
	while (processLive)
	{
	mainMenu:

		system("cls");

		cout << "What do you want to do? " << endl;
		cout << "1. Add player to team. " << endl;
		cout << "2. Show list of players. " << endl;
		cout << "3. Create file with players. " << endl;
		cout << "4. Exit..." << endl;
		
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
				dinamoList.addPlayer(createPlayer());
				goto pickPointOne;
			}

			if (pickOne == 2)
			{
				spartakList.addPlayer(createPlayer());
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
				dinamoList.showList();
				system("pause");
				goto pickPointTwo;
			}

			if (pickTwo == 2)
			{
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
		
			processLive = false;
			break;

		default:
			break;
		}
	}

	return 0;
}

//основной исполняемый файл

#include <iostream>
#include <string>
#include <fstream>							// библиотека для работы с потоками и файлами в следствии 
#include "player.h"
#include "playerList.h"
#include "Helper.h"

using namespace std;


int main()
{												// инициализация переменных необходимых для работы меню
	bool processLive = true;					// переменная для условия работы главного меню
								//2 списка команд и 1 общий, для создания подборки лучших игроков
	playerList dinamoList;						
	playerList spartakList;
	playerList bothTeamList;

	int pickOne, pickTwo, pickThree, choose;		//перменные выбора для координации в меню

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
		case 1:											//пункт меню для добавления игрока
		pickPointOne:

			system("cls");

			cout << "Which team's player you wanna add? " << endl;
			cout << "1. Dinamo. " << endl;
			cout << "2. Spartak. " << endl;
			cout << "3. Back..." << endl;
			cout << "> ";

			pickOne = getValuePick();

			if (pickOne == 1)										//добавление игрока в команду динамо
			{
				player dinamoPlayer = createPlayer(pickOne);
				dinamoList.addPlayer(dinamoPlayer);
				bothTeamList.addPlayer(dinamoPlayer);
				goto pickPointOne;
			}

			if (pickOne == 2)										//добавление игрока в команду спартак
			{
				player spartakPlayer = createPlayer(pickOne);
				spartakList.addPlayer(spartakPlayer);
				bothTeamList.addPlayer(spartakPlayer);
				goto pickPointOne;
			}

			if (pickOne == 3)										//выход в главное меню
			{
				goto mainMenu;
			}

		case 2:														//пункт меню для просмотра БД 
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
				if (dinamoList.getSize() == 0)									//небольшая проверка на наличие игроков в бд
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
				if (spartakList.getSize() == 0)									//небольшая проверка на наличие игроков в бд
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

		case 3:																	//пункт меню для создания файла с игроками
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

		case 4:															//пункт для создания файла с лучшими игроками

			if (bothTeamList.getSize() < 6)
			{
				cout << "Number of players is not enough!" << endl;
				system("pause");
				goto mainMenu;
			}

			bothTeamList.sortEfficiency();
			bothTeamList.createFileWithSixBestPlayers("bestplayersDB.txt");
			system("pause");
			goto mainMenu;

		case 5:															//пункт выхода из программы

			processLive = false;
			break;

		default:														//при некорректном вводе
			goto mainMenu;
		}
	}

	return 0;
}
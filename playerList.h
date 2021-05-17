//файл с двусвязным списком

#pragma once
#include "player.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	player player;
	Node* next, * prev;
};

class playerList
{
	Node* head, * tail;
	int size = 0;
public:

	int getSize();	// функция для получения размера списка

	void addPlayer(player);	// функция добавления игрока

	void sortEfficiency();	// функция для сортировки по эффективности сумма голов и голевых пасов

	void showList();	// функция вывода БД игроков в консоль

	void createFile(string fileName); // функция для создания файла отдельной команды

	void createFileWithSixBestPlayers(string);	// функция для создания файла с 6 лучшими игроками из обеих команд
};

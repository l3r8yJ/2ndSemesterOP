//���� � ���������� �������

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

	int getSize();	// ������� ��� ��������� ������� ������

	void addPlayer(player);	// ������� ���������� ������

	void sortEfficiency();	// ������� ��� ���������� �� ������������� ����� ����� � ������� �����

	void showList();	// ������� ������ �� ������� � �������

	void createFile(string fileName); // ������� ��� �������� ����� ��������� �������

	void createFileWithSixBestPlayers(string);	// ������� ��� �������� ����� � 6 ������� �������� �� ����� ������
};

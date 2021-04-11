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

	int getSize()
	{
		return size;
	}

	void addPlayer(player pl)
	{
		Node* temp = new Node;
		temp->next = NULL;
		temp->player = pl;

		if (head != NULL)
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
		else
		{
			temp->prev = NULL;
			head = tail = temp;
		}
		size++;
	}

	void sortEfficiency()
	{
		if (getSize() <= 0)
		{
			cout << "There's no players..." << endl;
			return;
		}

		Node* curr;
		Node* temp = head;
		player tempPlayer;

		while (temp != NULL)
		{
			curr = head;
			while (curr->next != NULL)
			{
				if (curr->player.getNumOfGoals() + curr->player.getNumOfGoalAssists() < curr->next->player.getNumOfGoals() + curr->next->player.getNumOfGoalAssists())
				{
					tempPlayer = curr->player;
					curr->player = curr->next->player;
					curr->next->player = tempPlayer;
				}
				curr = curr->next;
			}
			temp = temp->next;
		}
	}

	void showList()
	{
		Node* temp = head;

		cout << "+---------------------+-----------------+-------+----------+--------------+" << endl;
		cout << "|         Name        |      Team       | goals | assists  | penalty time |" << endl;
		cout << "+---------------------+-----------------+-------+----------+--------------+" << endl;

		while (temp != NULL)
		{
			cout << "| " << setw(19) << temp->player.getName() << " |" << setw(17) << temp->player.getTeam() << "| " << setw(6) << temp->player.getNumOfGoals() << "|" << setw(10) << temp->player.getNumOfGoalAssists() << "|" << setw(14) << temp->player.getPenaltyTime() << "|" << endl;			// add all fields of player later <- here
			cout << "+---------------------+-----------------+-------+----------+--------------+" << endl;
			temp = temp->next;
		}
	}

	void createFile(string fileName)
	{
		if (getSize() <= 0)
		{
			cout << "There's no players..." << endl;
			return;
		}

		ofstream dBase(fileName);
		Node* temp = head;

		while (temp != NULL)
		{
			dBase << "Player's name: " << temp->player.getName() << ", team: " << temp->player.getTeam() << ", goals: " << temp->player.getNumOfGoals() << ", asists: " << temp->player.getNumOfGoalAssists() << ", penalty time: " << temp->player.getPenaltyTime() << " mins." << endl;			// add all fields of player later <- here
			temp = temp->next;
		}
		dBase.close();
	}

	void createFileWithSixBestPlayers(string fileName)
	{
		if (getSize() <= 0)
		{
			cout << "There's no players..." << endl;
			return;
		}

		ofstream dBase(fileName);
		Node* temp = head;

		int stopper = 0;

		dBase << "TOP 6 PLAYERS: " << endl;

		while (temp != NULL && stopper < 6)
		{
			dBase << "Player's name: " << temp->player.getName() << ", team: " << temp->player.getTeam() << ", goals: " << temp->player.getNumOfGoals() << ", asists: " << temp->player.getNumOfGoalAssists() << ", penalty time: " << temp->player.getPenaltyTime() << " mins." << endl;			// add all fields of player later <- here
			temp = temp->next;
			stopper++;
		}
		dBase.close();
	}
};

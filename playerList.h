#pragma once
#include "player.h"
#include <iostream>
#include <fstream>

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
	playerList() :head(NULL), tail(NULL) {};

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

	void sort()
	{
		Node* temp = new Node;
		temp = head;
		while (temp->next != NULL)
		{
			if (temp->player.getEfficiency() < temp->next->player.getEfficiency());
			{
				player tempPlayer = temp->player;
				temp->player = temp->next->player;
				temp->next->player = tempPlayer;
			}

			temp = temp->next;
		}
	}

	void showList()
	{
		Node* temp = head;

		while (temp != NULL)
		{
			cout << "Player's name: " << temp->player.getName() << ", team: " << temp->player.getTeam() << ", goals: " << temp->player.getNumOfGoals() << ", asists: " << temp->player.getNumOfGoalAsists() << ", penalty time: " << temp->player.getPenaltyTime() << " mins." << endl;			// add all fields of player later <- here
			temp = temp->next;
		}
	}

	void createFile(string fileName)
	{
		ofstream dBase(fileName);
		Node* temp = head;

		while (temp != NULL)
		{
			dBase << "Player's name: " << temp->player.getName() << ", team: " << temp->player.getTeam() << ", goals: " << temp->player.getNumOfGoals() << ", asists: " << temp->player.getNumOfGoalAsists() << ", penalty time: " << temp->player.getPenaltyTime() << " mins." << endl;			// add all fields of player later <- here
			temp = temp->next;
		}
		dBase.close();
	}
};

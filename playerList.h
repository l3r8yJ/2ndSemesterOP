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
	playerList() : head(NULL), tail(NULL) {};

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

	void sortPlayerList()
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
				if (curr->player.getEfficiency() < curr->next->player.getEfficiency())
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

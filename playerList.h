#pragma once
#include "player.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	player p;
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
		temp->p = pl;

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

	void showList()
	{
		Node* temp = head;

		while (temp != NULL)
		{
			cout << "Player's name: " << temp->p.getName() << ", team: " << temp->p.getTeam() << ", goals: " << temp->p.getNumOfGoals() << ", asists: " << temp->p.getNumOfGoalAssists() << ", penalty time: " << temp->p.getPenaltyTime() << " mins." << endl;			// add all fields of player later <- here
			temp = temp->next;
		}
	}

	void createFile(string fileName)
	{
		ofstream dBase(fileName);
		Node* temp = head;

		while (temp != NULL)
		{
			dBase << "Player's name: " << temp->p.getName() << ", team: " << temp->p.getTeam() << ", goals: " << temp->p.getNumOfGoals() << ", asists: " << temp->p.getNumOfGoalAssists() << ", penalty time: " << temp->p.getPenaltyTime() << " mins." << endl;			// add all fields of player later <- here
			temp = temp->next;
		}
		dBase.close();
	}
};

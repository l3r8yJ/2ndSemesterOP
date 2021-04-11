//���� ��� ���������� �������� ������� ����������, � �������� ��� �������� ������������ �����.

#pragma once

bool haveNumber(string line) //�������� �� ������� ���� � �����
{
	int i = 0;

	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			return true;
		}
		i++;
	}

	return false;
}

int getParameter() // ������� ��� �������� ���������� �����, ������, � ��������� �������
{
valuePick:
	int value;

	cin >> value;

	if (cin.fail())
	{
		cout << "Incorrect input, try again please..." << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto valuePick;
	}

	return value;
}

int getValuePick() // ������� ������������ ����� ��� ������ ������� � ������� ���� ��� �������� 1, 2 ,3
{
valuePick:

	int value;

	cin >> value;

	if (cin.fail())
	{
		cout << "Incorrect input, try again please..." << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto valuePick;
	}

	switch (value)
	{
	case 1: return value;
	case 2: return value;
	case 3: return value;
	default:
		cout << "Incorrect input, try again please..." << endl;
		goto valuePick;
		break;
	}

	return value;
}

int getValueMainMenu()	// ������� ��� �������� ������������ ����� � ������� ����
{
	int value;
	cin >> value;

	if (cin.fail() || value < 1 || value > 5)
	{
		cout << "Incorrect input, try again please..." << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}

	return value;
}

player createPlayer(int pickOne)		// ������� �������� ������, ��������� ������� ���������� ����� ������������ � �������� �������������
{
	player thisPlayer;

	string name, team;
	int goal, assist, penalty;

namePoint:
	cout << "Enter the name of player: " << endl;
	cout << "> ";
	cin >> name;

	name[0] = toupper(name[0]);										// �������� ������ ����� � ������� �������, ���� ������������ ���� ����������� 

	if (haveNumber(name))
	{
		cout << "Name can't contain numbers, enter name again please." << endl;
		goto namePoint;
	}

	if (pickOne == 1)										// ����������� �������
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

goalPoint:																// ���������� ����������
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
															//�������� ����������
	thisPlayer.setName(name);
	thisPlayer.setTeam(team);
	thisPlayer.setNumOfGoals(goal);
	thisPlayer.setNumOfGoalAssists(assist);
	thisPlayer.setPenaltyTime(penalty);

	return thisPlayer;
}
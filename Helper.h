//���� ��� ���������� �������� ������� ����������, � �������� ��� �������� ������������ �����.

#pragma once

bool haveNumber(string line) //�������� �� ������� ���� � �����
{
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			cout << "Have number!";
			return true;
		}
	}

	return false;
}

bool haveSpaces(string line)	// �������� �� ������� �������� � �����
{
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ')
		{
			cout << "Have space!";
			return true;
		}
	}

	return false;
}

bool haveIncorrectSize(string line)		// �������� �� ����� ����� 
{
	if (line.length() < 3)
	{
		cout << "Have length lower then 3!";
		return true;
	}
	return false;
}

bool haveIncorrectChar(string line)					//�������� �� ���������� ������������ �������� �� ���� %, !, � ��
{
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '!' || line[i] == '@' || line[i] == '#' || line[i] == '$' || line[i] == '%' || line[i] == '^' || line[i] == '&' || line[i] == '*' || line[i] == '(' || line[i] == ')' || line[i] == ':' || line[i] == '?' || line[i] == '"' || line[i] == '_' || line[i] == '-' || line[i] == '+' || line[i] == '[' || line[i] == ']' || line[i] == '{' || line[i] == '}' || line[i] == ',' || line[i] == '.' || line[i] == '<' || line[i] == '>' || line[i] == '~' || line[i] == '`' || line[i] == '|' || line[i] == '/')
		{
			cout << "Have incorrect character -> " << line[i];
			return true;
		}
	}
	return false;
}

bool isCorrectFinal(string line)
{
	if (haveSpaces(line))
	{
		return false;
	}

	else if (haveNumber(line))
	{
		return false;
	}

	else if (haveIncorrectSize(line))
	{
		return false;
	}

	else if (haveIncorrectChar(line))
	{
		return false;
	}
	
	return true;
}

string getNameParameter()
{
	string value;
	bool correct = true;

valuePick:

	cin >> value;

	value[0] = toupper(value[0]);										// �������� ������ ����� � ������� �������, ���� ������������ ���� ����������� 

	if (isCorrectFinal(value) != correct)										// ������ �������� �����
	{
		cout << " Try again." << endl;
		cout << "> ";
		goto valuePick;
	}

	return value;
}

int getParameter() // ������� ��� �������� ���������� �����, ������, � ��������� �������
{
valuePick:

	int value;
	cin >> value;

	if (cin.fail())
	{
		cout << "Incorrect input, try again please..." << endl;
		cout << "> ";
		cin.clear();
		cin.ignore(32767, '\n');
		goto valuePick;
	}

	if (value < 0)
	{
		cout << "Wrong value! " << endl;
		cout << "> ";
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
		cout << "> ";
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
		cout << "> ";
		goto valuePick;
		break;
	}

	cin.clear();
	cin.ignore(32767, '\n');
	return value;
}

int getValueMainMenu()	// ������� ��� �������� ������������ ����� � ������� ����
{
	int value;
	cin >> value;

	if (cin.fail() || value < 1 || value > 5)
	{
		cout << "Incorrect input, try again please..." << endl;
		cout << "> ";
		cin.clear();
		cin.ignore(32767, '\n');
	}

	return value;
}


string autoTeam(int pickOne)               // ����������� �������
{
	string team;

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

	return team;
}


player createPlayer(int pickOne)		// ������� �������� ������, ��������� ������� ���������� ����� ������������ � �������� �������������
{
	player thisPlayer;
	string name;
	int goal, assist, penalty;

	cout << "Enter the name of player: " << endl;
	cout << "> ";
	name = getNameParameter();
																				// ���������� ����������
	cout << "Enter the number of goals that player did: " << endl;
	cout << "> ";
	goal = getParameter();

	cout << "Enter the number of asists that player did: " << endl;
	cout << "> ";
	assist = getParameter();

	cout << "Enter player's penalty time: " << endl;
	cout << "> ";
	penalty = getParameter();
															//�������� ����������
	thisPlayer.setName(name);
	thisPlayer.setTeam(autoTeam(pickOne));
	thisPlayer.setNumOfGoals(goal);
	thisPlayer.setNumOfGoalAssists(assist);
	thisPlayer.setPenaltyTime(penalty);

	return thisPlayer;
}
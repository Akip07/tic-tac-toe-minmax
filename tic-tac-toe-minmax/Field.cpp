#include "Field.h"
#include<vector>
Board::Board(int n)
{
	this->n = n;
	for (int i = 0; i < n; i++)
	{
		vector <char> temp;
		for (int j = 0; j < n; j++)
		{
			temp.push_back(NULL);
		}
		fields.push_back(temp);
	}
}

void Board::Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (fields[i][j] == NULL)
			{
				std::cout << " ";
			}
		else
				std::cout << fields[i][j];
		if (j != n - 1)
		{
			std::cout << "|";
		}
		}
		std::cout << "\n";
		if (i != n - 1)
		{
			for (int k = 0; k < n; k++)
			{
				std::cout << "==";
			}
			std::cout << "\n";
		}
	}
}

void Board::MakeMove(int x, int y, char v)
{
		fields[y][x] = v;
		!player;
}

void Board::MakeMove(int x, int y, bool p)
{
	char v;
	if (p)
		v = 'X';
	else
		v = 'O';
	MakeMove(x, y, v);
}

char Board::CheckWin()
{
	int n = Size();


	char field = CheckField(0, 0);
	if (field)
		for (int j = 1; j < n; j++) {
			if (CheckField(j, j) != field)
				break;
			else if (j == n - 1)
				return field;
		}

	field = CheckField(n - 1, n - 1);
	if (field)
		for (int j = n-1; j >= 0; j--)
		{
			if (CheckField(j, j) != field)
				break;
			else if (j == 0)
				return field;
		}
	 
	for (int i = 0; i < n; i++)
	{
		field = CheckField(i, 0);
		if (field)
			for (int j = 1; j < n; j++)
			{
				if (CheckField(i, j) != field)
					break;
				else if (j == n - 1)
					return field;
			}

		field = CheckField(0, i);
		if (field)
			for (int j = 1; j < n; j++)
			{
				if (CheckField(j, i) != field)
					break;
				else if (j == n - 1)
					return field;
			}

	}
	return NULL;
}

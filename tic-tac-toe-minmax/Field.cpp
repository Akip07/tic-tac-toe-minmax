#include "Field.h"
#include<vector>
#include<iostream>
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


char Board::CheckField(int y, int x)
{
	char temp;
	temp = fields[y][x]; return temp;
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

void Board::MakeMove(int y, int x, char v)
{
		fields[y][x] = v;
		
}

void Board::MakeMove(int y, int x, bool p)
{
	char v;
	if (p)
		v = 'X';
	else
		v = 'O';
	MakeMove(y, x, v);
}

char Board::CheckWin()
{
	for (int row = 0; row < Size(); row++)
	{
		char field = (row, 0);
		for (int col = 0; col < Size(); col++)
		{
			if (field != (row, col))
			{
				break;
			}
			else if (col == Size() - 1)
			{
				return field;
			}
		}
	}


	for (int col = 0; col < Size(); col++)
	{
		char field = (0, col);
		for (int row = 0; row < Size(); row++)
		{
			if ((row, col) != field)
			{
				break;
			}
			else if (row == Size() - 1)
			{
				return field;
			}
		}
	}


	char field = (0, 0);
	for (int i = 1; i < Size(); i++)
	{
		if ((i, i) != field)
		{
			break;
		}
		else if (i == (Size() - 1))
		{
			return field;
		}
	}


	field = (0, Size() - 1);
	for (int i = 0; i < Size(); i++)
	{
		if (field != (i, Size() - 1 - i))
		{
			break;
		}
		else if (i == Size() - 1)
		{
			return field;
		}
	}

	return 0;
}

bool Board::MovesLeft()
{
	for (int i = 0; i < Size(); i++)
		for (int j = 0; j < Size(); j++)
		{
			if (CheckField(i, j)== NULL)
			return true;
		}
	return false;
}
char& Board::operator()(int row, int column) //first y then x
{
	return fields[row][column];
}





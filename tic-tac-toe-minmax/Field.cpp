#include "Field.h"

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

void Board::MakeMove(int r, int c, char v)
{
	fields[c][r] = v;
}

#pragma once
#include <conio.h>
#include<iostream>
#include "Field.h"
using std::cout;
void MoveMessage(bool player)
{
	cout << "Ruch gracza ";
	if (player == 0)
		cout << "O";
	else
		cout << "X";
}

char CheckWin(Board b)
{
	int n = b.Size();


	char field = b.CheckField(0, 0);
	if(field)
	for (int j = 1; j < n; j++)		{
			if (b.CheckField(j, j) != field)
				break;
			else if (j == n - 1)
				return field;
	}

	field = b.CheckField(n-1, n-1);
	if (field)
	for (int j = n; j >=0; j--)
	{
			if (b.CheckField(j, j) != field)
				break;
			else if (j == 0)
				return field;
	}

	for (int i = 0; i < n; i++)
	{
		field = b.CheckField(i,0);
		if(field)
		for (int j = 1; j <n; j++)
		{
			if (b.CheckField(i, j) != field)
				break;
			else if (j == n - 1)
				return field;
		}

		field = b.CheckField(0, i);
		if(field)
		for (int j = 1; j < n; j++)
		{
			if (b.CheckField(j, i) != field)
				break;
			else if (j == n - 1)
				return field;
		}

	}
	return NULL;
}
void Play()
{
	int n;
	cout << "Podaj liczbe pol:\n";
	std::cin >> n;
	Board b(n);
	bool player = 0;
	char p=0;
	while (1)
	{
		
		if (player)
			p = 'X';
		else
			p = 'O';

		system("cls");
		b.Print();

		cout << "Ruch gracza "<<p<<"\nPodaj wspolrzedne pola do zmiany(x, t) :\n";
		int x, y;
		std::cin >> x >> y;
		if (!b.CheckField(x, y))
		{
			b.MakeMove(x, y, p);
		}
		if (CheckWin(b))
		{
			break;
		}

		player = !player;
	}
	cout << "\nZWYCIEZCA: GRACZ "<<p;

}
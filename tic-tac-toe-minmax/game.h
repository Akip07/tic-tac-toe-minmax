#pragma once
#include <conio.h>
#include<iostream>
#include "Field.h"
#include<vector>
//#include "Bot.h"
using std::cout;


void Play()
{
	int n;
	cout << "Podaj liczbe pol:\n";
	std::cin >> n;
	Board b(n);
	char p=0;
	while (1)
	{
		
		if (b.CheckPlayer())
			p = 'X';
		else
			p = 'O';

		system("cls");
		b.Print();

		cout << "Ruch gracza "<<p<<"\nPodaj wspolrzedne pola do zmiany(x, y) :\n";
		int x, y;
		while (1)
		{
			std::cin >> x >> y;
			if (x >= 0 &&y>=0&&x<n&&y<n&& !b.CheckField(y, x))
			{
				b.MakeMove(x, y, p);
				break;
			}
			else
			{
				std::cout<<"wybierz poprawna wartosc";
			}
		}
		if (b.CheckWin())
		{
			break;
		}

	}
	cout << "\nZWYCIEZCA: GRACZ "<<p;

}
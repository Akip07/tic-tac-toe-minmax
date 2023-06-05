#pragma once
#include <conio.h>
#include<iostream>
#include "Field.h"
#include<vector>
#include "minmax.h"
#include <conio.h>
using std::cout;


void Play()
{
	int n;
	cout << "Podaj liczbe pol:\n";
	std::cin >> n;
	Board b(n);
	int depth;
	if (n == 3)
		depth = 10;
	else
		depth = 7;
	bool isBot=1;
	while (1)
	{
		isBot = !isBot;
		system("cls");
		b.Print();
		
		if (isBot == false)
		{
			
			std::cout << "\nRuch gracza O\nWybierz pole (rzad, kolumna)\n";
			int row, col;
			while(1)

			{
				
				std::cin >> row >> col;
				if (0 <= row && 0<=col && row< n && col < n)
					break;
				else
					std::cout << "wybrana wartosc jest niepoprawna, wybierz wartosc w zakresie od 0 do " << n << "\n";

			}
			b.MakeMove(row, col, isBot);

		}
		else
		{
			std::cout << "Bot wykonuje ruch...\n";
			Move bm = BotMove(b, depth);
			system("cls");
			std::cout << "bot wykonal ruch:\trzad: " << bm.row << "\tkolumna: " << bm.col << "\n";
			b.Print();
			std::cout << "nacisnij dowolny przycisk by kontynuowac\n";

			_getch();
		}

		if (b.CheckWin())
		{
			break;
		}

	}
	cout << "\nZWYCIEZCA:"<<b.CheckWin();
	

}
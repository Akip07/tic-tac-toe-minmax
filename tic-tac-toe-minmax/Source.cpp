#include<iostream>
#include<vector>

#include"game.h"
//#include"Field.h"
#include"Bot.h"

int main()
{
	//Play();
	Board b(2);
	
		b.Print();
		int x, y;
		std::cin >> x >> y;
		b.MakeMove(x-1, y-1, 'O');
		//b.Print();
		Evaluate(b);
		b.Print();

	
	


}
#include<iostream>
#include<vector>


#include"minmax.h"




int main()
{
	Board board(5);


	while (1)
	{
		int x, y;
		cin >> y >> x;
		board(y, x) = 'O';
		findBestMove(board,6);
		board.Print();
	}
	cout << board.Size()<<"\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board(i, j) == NULL)
				cout << "#";
			else
				cout << board(i, j);
		}
		cout << endl;
	}
		
	return 0;
}




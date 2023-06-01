#pragma once

#include"Field.h"

int Evaluate(Board &startBoard, int level =0)
{
	int x=0;
	int y=0;
	int score = 0;
	Board b = startBoard;
	for(int i = 0; i<b.Size();i++)
		for (int j = 0; j < b.Size(); j++)
		{	
			b = startBoard;
			if (b.CheckField(i, j)!= NULL)
			{
				int temp = 0;
				bool p = b.CheckPlayer();
				b.MakeMove(i, j, p);
				char win = b.CheckWin();

				if (win == 'X')
					score = 1;
				else if (win == 'O')
					score = -1;
				else if (!win)
					temp += Evaluate(b,level +1);

				if (p && temp>score)
				{
					score = temp;
					x = i;
					y = j;
				}
				else if (!p && temp<score)
				{
					score = temp;
					x = i;
					y = j;
				}
			}


		}
	if (level == 0 && !b.CheckField(x,y))
	{
		startBoard.MakeMove(x,y,'X');
		
	}
	std::cout << "dupa";

	return score;
}
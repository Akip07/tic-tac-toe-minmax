#pragma once
#include <iostream>
#include"Field.h"

struct Move
{
	int row, col;
};

char player = 'X', opponent = 'O';


int evaluate(Board b)
{
	for (int row = 0; row < b.Size(); row++)
	{
		char field = b(row, 0);
		for (int col = 0; col < b.Size(); col++)
		{
			if (field != b(row, col))
			{
				break;
			}
			else if (col == b.Size() - 1)
			{
				if (b(row, 0) == player)
					return +10;
				else if (b(row, 0) == opponent)
					return -10;
			}
		}
	}


	for (int col = 0; col < b.Size(); col++)
	{
		char field = b(0, col);
		for (int row = 0; row < b.Size(); row++)
		{
			if (b(row, col) != field)
			{
				break;
			}
			else if (row == b.Size() - 1)
			{
				if (field == player)
					return +10;
				else if (field == opponent)
					return -10;
			}
		}
	}


	char field = b(0, 0);
	for (int i = 1; i < b.Size(); i++)
	{
		if (b(i, i) != field)
		{
			break;
		}
		else if (i == (b.Size() - 1))
		{
			if (field == player)
				return +10;
			else if (field == opponent)
				return  -10;
		}
	}

	field = b(0, b.Size() - 1);
	for (int i = 0; i < b.Size(); i++)
	{
		if (field != b(i, b.Size() - 1 - i))
		{
			break;
		}
		else if (i == b.Size() - 1)
		{
			if (field == player)
				return +10;
			else if (field == opponent)
				return (-10);
		}
	}

	return 0;
}


int minimax(Board board, int depth, bool isMax, int maxdepth, int alpha = -10000, int beta = 10000)
{
	char null = NULL;
	int score = evaluate(board);

	if (score != 0 || depth == maxdepth)
		return score;


	if (board.MovesLeft() == false)
		return 0;

	if (isMax)
	{
		int best = -1000;

		for (int i = 0; i < board.Size(); i++)
		{
			for (int j = 0; j < board.Size(); j++)
			{
				if (board(i, j) == NULL)
				{
					board(i, j) = player;

					int temp = minimax(board, depth + 1, !isMax, maxdepth, alpha, beta);
					best = std::max(best, temp);
					alpha = std::max(alpha, temp);


					board(i, j) = NULL;
					if (beta <= alpha)
						break;
				}
				if (beta <= alpha)
					break;
			}
			if (beta <= alpha)
				break;
		}
		return best;
	}


	else
	{
		int best = 1000;

		for (int i = 0; i < board.Size(); i++)
		{
			for (int j = 0; j < board.Size(); j++)
			{
				if (board(i, j) == NULL)
				{
					board(i, j) = opponent;


					int temp = minimax(board, depth + 1, !isMax, maxdepth, alpha, beta);
					best = std::min(best, temp);
					beta = std::min(beta, temp);

					board(i, j) = NULL;

					if (beta <= alpha)
						break;
				}
				if (beta <= alpha)
					break;
			}
			if (beta <= alpha)
				break;
		}
		return best;
	}
}

Move BotMove(Board& board, int maxdepth)
{
	char null = NULL;
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i < board.Size(); i++)
	{
		for (int j = 0; j < board.Size(); j++)
		{
			if (board(i, j) == NULL)
			{
				board(i, j) = player;

				int moveVal = minimax(board, 0, false, maxdepth);

				board(i, j) = NULL;

				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	board.MakeMove(bestMove.row, bestMove.col, 'X');
	return bestMove;

}
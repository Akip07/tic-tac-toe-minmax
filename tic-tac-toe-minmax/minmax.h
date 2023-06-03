#pragma once
#include <iostream>
#include"Field.h"

using namespace std;

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
				return  -10;
		}
	}

	return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(Board board, int depth, bool isMax, int maxdepth, int alpha=-10000, int beta=10000)
{
	char null = NULL;
	int score = evaluate(board);

	if (score != 0|| depth == maxdepth)
		return score;

	// If there are no more moves and no winner then
	// it is a tie
	if (board.MovesLeft() == false)
		return 0;

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i < board.Size(); i++)
		{
			for (int j = 0; j < board.Size(); j++)
			{
				// Check if cell is empty
				if (board(i, j) == NULL)
				{
					// Make the move
					board(i, j) = player;

					int temp = minimax(board, depth + 1, !isMax, maxdepth, alpha, beta);
					best = max(best,temp);
					alpha = max(alpha, temp);
					

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

		// Traverse all cells
		for (int i = 0; i < board.Size(); i++)
		{
			for (int j = 0; j < board.Size(); j++)
			{
				// Check if cell is empty
				if (board(i, j) == NULL)
				{
					// Make the move
					board(i, j) = opponent;


					// Call minimax recursively and choose
					// the minimum value
					int temp = minimax(board, depth + 1, !isMax, maxdepth, alpha, beta);
					best = min(best, temp);
					beta = min(beta, temp);
					
					// Undo the move
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

// This will return the best possible move for the player
void findBestMove(Board& board, int maxdepth)
{
	char null = NULL;
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	// Traverse all cells, evaluate minimax function for
	// all empty cells. And return the cell with optimal
	// value.
	for (int i = 0; i < board.Size(); i++)
	{
		for (int j = 0; j < board.Size(); j++)
		{
			// Check if cell is empty
			if (board(i, j) == NULL)
			{
				// Make the move
				board(i, j) = player;
				//board.MakeMove(i, j, player);

				// compute evaluation function for this
				// move.
				int moveVal = minimax(board, 0, false, maxdepth);

				// Undo the move
				board(i, j) = NULL;
				//board.MakeMove(i, j, null);

				// If the value of the current move is
				// more than the best value, then update
				// best/
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

	//return bestMove;
}

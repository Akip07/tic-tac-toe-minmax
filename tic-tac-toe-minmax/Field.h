#pragma once
#include<iostream>
#include<vector>;
using std::vector;


class Board
{
private:
	int n;
	vector<vector<char>> fields;
	bool player=0;
public:
	Board(int n);
	void Print();
	int Size() { return n; }
	void MakeMove(int, int, char);
	void MakeMove(int, int, bool);
	char CheckWin();
	char CheckField(int column, int row) { char temp;  temp = fields[column][row]; return temp; }
	bool CheckPlayer() { return player; }

};



#pragma once
#include<iostream>
#include<vector>;
using std::vector;


class Board
{
private:
	int n;
	vector<vector<char>> fields;
public:
	Board(int n);
	void Print();
	int Size() { return n; }
	void MakeMove(int, int, char);
	void MakeMove(int, int, bool);
	char CheckWin();
	bool MovesLeft();
	char& operator()(int, int);
	char CheckField(int, int);

};



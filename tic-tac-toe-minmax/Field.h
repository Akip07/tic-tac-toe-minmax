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
	char CheckField(int column, int row) { char temp;  temp = fields[column][row]; return temp; }
};



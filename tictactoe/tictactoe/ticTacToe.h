#pragma once

class ticTacToe
{
public:
	
	//
	void printBoard();
	void getMove1(int);
	void getMove2(int);
	bool isValidMove(int, int);
	bool Winner1();
	bool Winner2();
	bool Draw();
	void reset();
	ticTacToe();

private: 
	// array for the board 	
	char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ',' ',' '} };
};

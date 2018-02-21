#include<iostream>
#include<iomanip>
#include "ticTacToe.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
//
//
//function to reset the 2D array back to ' '
//
//
//////////////////////////////////////////////////////////////////////////////////
void ticTacToe::reset()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';
}

//////////////////////////////////////////////////////////////////////////////////
//
//     function to print out the array board
//
//              |   |
//          -------------
//              |   |
//          -------------
//              |   |
//
//
/////////////////////////////////////////////////////////////////////////////////
void ticTacToe::printBoard()
{

	cout << endl << endl;
	cout << "     " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout <<  "   " <<  "-------------" << endl;
	cout << "     " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout <<  "   " <<  "-------------" << endl;
	cout << "     " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;

}

/////////////////////////////////////////////////////////////////////////////////
//
//
//  function to make all index's in the 2D array to display ' '  
//
//
////////////////////////////////////////////////////////////////////////////////
ticTacToe::ticTacToe()
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++) 
			board[row][col] = ' ';
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//function containing a switch satement to validate the move in each index of the 2D array for player 1.
//if move is invalid function will print out Invalid Move to the player.
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ticTacToe::getMove1(int num)
{
	bool validate = false;
	switch (num)
		{
		case 1:
			validate = isValidMove(0, 0);
			if (validate == true)
				board[0][0] = 'X';
			break;
		case 2:
			validate = isValidMove(0, 1);
			if (validate == true)
				board[0][1] = 'X';
			break;
		case 3:
			validate = isValidMove(0, 2);
			if (validate == true)
				board[0][2] = 'X';
			break;
		case 4:
			validate = isValidMove(1, 0);
			if (validate == true)
				board[1][0] = 'X';
			break;
		case 5:
			validate = isValidMove(1, 1);
			if (validate == true)
				board[1][1] = 'X';
			break;
		case 6:
			validate = isValidMove(1, 2);
			if (validate == true)
				board[1][2] = 'X';
			break;
		case 7:
			validate = isValidMove(2, 0);
			if (validate == true)
				board[2][0] = 'X';
			break;
		case 8:
			validate = isValidMove(2, 1);
			if (validate == true)
				board[2][1] = 'X';
			break;
		case 9:
			validate = isValidMove(2, 2);
			if (validate == true)
				board[2][2] = 'X';
			break;
		default:
			cout << "\nInvalid input." << endl;
		}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// if move is Valid function will check the row and coloum and replace '*' with 'X' and or 'O' for player 1 and 2.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ticTacToe::isValidMove(int row, int col)
{
	if (board[row][col] == 'X' || board[row][col] == 'O')
		return false;
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// function containing a switch satement to validate the moves on the board for player 2
// if move is invalid function will print out Invalid Move to the player.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ticTacToe::getMove2(int num)
{
	bool validate = false;
	switch (num)
	{
	case 1:
		validate = isValidMove(0, 0);
		if (validate == true)
			board[0][0] = 'O';
		break;
	case 2:
		validate = isValidMove(0, 1);
		if (validate == true)
			board[0][1] = 'O';
		break;
	case 3:
		validate = isValidMove(0, 2);
		if (validate == true)
			board[0][2] = 'O';
		break;
	case 4:
		validate = isValidMove(1, 0);
		if (validate == true)
			board[1][0] = 'O';
		break;
	case 5:
		validate = isValidMove(1, 1);
		if (validate == true)
			board[1][1] = 'O';
		break;
	case 6:
		validate = isValidMove(1, 2);
		if (validate == true)
			board[1][2] = 'O';
		break;
	case 7:
		validate = isValidMove(2, 0);
		if (validate == true)
			board[2][0] = 'O';
		break;
	case 8:
		validate = isValidMove(2, 1);
		if (validate == true)
			board[2][1] = 'O';
		break;
	case 9:
		validate = isValidMove(2, 2);
		if (validate == true)
			board[2][2] = 'O';
		break;
	default:
		cout << "\nInvalid input." << endl;
	}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//this function will determain if player 1 is the winner each loop until a match is found for both 
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ticTacToe::Winner1()
{
	for (int row = 0; row < 3; row++)
	{
		int count = 0;
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] == 'X')
				count = count + 1;
			if (count >= 3)
				return true;
		}
	}
	
	for (int col = 0; col < 3; col++)
	{
		int count = 0;
		for (int row = 0; row < 3; row++)
		{
			if (board[row][col] == 'X')
				count = count + 1;
			if (count >= 3)
				return true;
		}
	}

	for (int row1 = 0; row1 < 3; row1++)
	{
		if (board[0][0] == 'X' && board[1][1] == 'X')
			if (board[2][2] == 'X')
				return true;
		if (board[0][2] == 'X' && board[1][1] == 'X')
			if (board[2][0] == 'X')
				return true;

	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//this function will determain if player 2 is the winner each loop until a match is found for both 
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ticTacToe::Winner2()
{
	for (int row = 0; row < 3; row++)
	{
		int count = 0;
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] == 'O')
				count = count + 1;
			if (count >= 3)
				return true;
		}
	}

	for (int col = 0; col < 3; col++)
	{
		int count = 0;
		for (int row = 0; row < 3; row++)
		{
			if (board[row][col] == 'O')
				count = count + 1;
			if (count >= 3)
				return true;
		}
	}
	for (int row1 = 0; row1 < 3; row1++)
	{
		if (board[0][0] == 'O' && board[1][1] == 'O')
			if (board[2][2] == 'O')
				return true;
		if (board[0][2] == 'O' && board[1][1] == 'O')
			if (board[2][0] == 'O')
				return true;

	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//  this function will determain a draw is the winner each loop until a match is found for both 
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ticTacToe::Draw()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] == ' ')
				return false;
		}
	}
	return true;
}
#include<iostream>
#include "ticTacToe.h"

using namespace std;

void instructions();
void play();

int main()
{
	int choice;
	do 
	{
		//options before the game starts player gets prompted to select an option
		cout << "Tic Tac Toe" << endl;
		cout << "To see Instructions, press 1" << endl;
		cout << "To Play, enter 2." << endl;
		cout << "To Exit, enter 3." << endl;
		cin >> choice;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		cout << endl;

		//switch statement to determain what options you would like 1 to play, 2 for instructions and 3 to exit
		switch (choice)
		{
		case 1:
			instructions();
			break;
		case 2:
			play();
			break;
		default:
			break;
		}
	} 
	// pressing 3 quits the application
	while (choice != 3);
	return 0;

}
void instructions()
{
	//some instructions for the game to explain what numbers are usable for the board 
	cout << "The object of the game is to get 3 X's or 3 O's in a row." << endl;
	cout << "The X, player 1 gets to move first." << endl;
	cout << "The board locations are as follows" << endl;
	cout << " 1   2   3" << endl;
	cout << " 4   5   6" << endl;
	cout << " 7   8   9" << endl << endl;

}

void play()
{
	//play function prints the board 
	system("cls");
	int num;
	static ticTacToe board;
	static ticTacToe reset;
	bool status = false;
	board.printBoard();
	while (status == false)
	{
		//statment to check player 1's inputs if there is a draw or if player 1 has won the game.
		cout << "\nEnter (Player 1): " << endl;
		cin >> num;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}
		board.getMove1(num);
		system("cls");
		board.printBoard();
		if (board.Draw() == true)
		{
			status = true;
			cout << "\nDraw!!!" << endl;
			board.reset();
		}
		if (board.Winner1() == true)
		{
			status = true;
			cout << "\nPlayer 1 Wins!!!" << endl;
			board.reset();
		}
		else 
		//else statment to check player 2's inputs if there is a draw or if player 2 has won the game.
		{

			cout << "\nEnter (Player 2): " << endl;
			cin >> num;
			if (!cin)
			{
				cin.clear();
				cin.ignore(100, '\n');
			}
			board.getMove2(num);
			system("cls");
			board.printBoard();
			if (board.Draw() == true)
			{
				status = true;
				cout << "\nDraw!!!" << endl;
				board.reset();
			}
			if (board.Winner2() == true)
			{
				status = true;
				cout << "\nPlayer 2 Wins!!!" << endl;
				board.reset();
			}
		}
	}
}
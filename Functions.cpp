#include "Functions.h"

void runGame()
{
	int row;
	int col;
	char piece;
	char board[3][3];
	int result;
	char game;
	char Y;
	char y;
	Y = 'Y';
	y = 'y';
	game = 'Y';
	//while loop to start the game over if the user wants to
	while ((game == Y) || (game == y)) {
		piece = 'X';
		result = 0;
		initBoard(board);
		cout << "Enter coordinate for X. Input should be X Y" << endl;
		cin >> row >> col;
		placeAPiece(row, col, piece, board);
		displayBoard(board);
		char X;
		X = 'X';
		while (result == 0) {
			if (piece == X) {
				piece = 'O';
			}
			else {
				piece = 'X';
			}
			cout << "Enter coordinate for " << piece << ". Input should be X Y" << endl;
			cin >> row >> col;
			placeAPiece(row, col, piece, board);
			displayBoard(board);
			if (checkForWinner(piece, board)) {
				result = 1;
				cout << piece << " Won" << endl;
			}
			else {
				result = 0;
				if (checkForDraw(board)) {
					result = 1;
					cout << "Draw" << endl;
				}
			}
		}
		cout << "Do you want to play again?" << endl;
		cin >> game;
	}
	cout << "Done" << endl;
}

void initBoard(char board[3][3])
{
	//clears the board by filling in all the indexs with '-'
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			board[row][col] = '-';
		}
	}
}

void placeAPiece(int x, int y, char piece, char board[3][3])
{
	//puts the piece in the specified index
	board[x][y] = piece;
}

bool checkForWinner(char piece, char board[3][3])
{
	//checks to see if theres is 3 pieces in a horizontal line
	for (int row = 0; row < 3; row++) {
		if (board[row][0] == piece) {
			if (board[row][1] == piece) {
				if (board[row][2] == piece) {
					return true;
				}
			}
		}
	}
	//checks to see if there is 3 pieces in a vertical line
	for (int col = 0; col < 3; col++) {
		if (board[0][col] == piece) {
			if (board[1][col] == piece) {
				if (board[2][col] == piece) {
					return true;
				}
			}
		}
	}
	//checks to see if there is 3 pieces in a diagonal line
	if (board[0][0] == piece) {
		if (board[1][1] == piece) {
			if (board[2][2] == piece) {
				return true;
			}
		}
	}
	if (board[0][2] == piece) {
		if (board[1][1] == piece) {
			if (board[2][0] == piece) {
				return true;
			}
		}
	}
	return false;
}

bool checkForDraw(char board[3][3])
{
	//checks to see if every index in the board is filled with pieces
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (board[row][col] == '-') {
				return false;
			}
		}
	}
	return true;
}


void displayBoard(char board[3][3])
{
	//prints out the board
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (col < 2) {
				cout << board[row][col] << "|";
			}
			else {
				cout << board[row][col] << endl;
			}
		}
		if (row < 2) {
			cout << "-----" << endl;
		}
	}
}
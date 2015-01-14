#include <iostream>
#define SIZE 3
using namespace std;

void chooseSign(char& playerOne, char& playerTwo);
void populateTable(char TicTacToe[SIZE][SIZE]);
void printBoard(char TicTacToe[SIZE][SIZE]);
void printStatus(char& playerTurn, int moveNumber, char pO, char pT);
void playMove(char playerMove, char TicTacToe[SIZE][SIZE]);
void setLocation(int location, int& locationX, int& locationY);
void checkWinner(char TicTacToe[SIZE][SIZE], char& winner);

void main(){
	char playerOne = ' ', playerTwo = ' ', playerTurn = ' ';
	char TicTacToe[SIZE][SIZE]; int moveNumber = 1;
	char winner = ' ';

	populateTable(TicTacToe);
	chooseSign(playerOne, playerTwo);
	while (1){
		system("CLS");
		printStatus(playerTurn, moveNumber, playerOne, playerTwo);
		printBoard(TicTacToe);
		playMove(playerTurn, TicTacToe);
		checkWinner(TicTacToe, winner);
		system("CLS");
		printStatus(playerTurn, moveNumber, playerOne, playerTwo);
		printBoard(TicTacToe);
		
		if (moveNumber == 9){ (winner == ' ') ? cout << "There is no winner!\n" : cout << "The winner is: " << winner<<".\n"; break; };
		if (winner != ' '){ cout << "The winner is: " << winner << ".\n"; break; }
		moveNumber++;
	}
	system("PAUSE");
}

void chooseSign(char& playerOne, char& playerTwo){
	while (1){
		cout << "Please enter X or O: "; cin >> playerOne;
		if (playerOne == 'x'){ playerOne = 'X'; playerTwo = 'O'; break; }
		else if (playerOne == 'X'){ playerOne = 'X'; playerTwo = 'O'; break; }
		else if (playerOne == 'o'){ playerOne = 'O'; playerTwo = 'X'; break; }
		else if (playerOne == 'O'){ playerOne = 'O'; playerTwo = 'X'; break; }
		else { cout << "Your input is wrong, try again: \n"; }
	}
}

void populateTable(char TicTacToe[3][3])
{
	for (int column = 0; column < 3; column++)
		for (int row = 0; row < 3; row++)
		{
			TicTacToe[column][row] = ' ';
		}
}

void printStatus(char& playerTurn, int moveNumber, char pO, char pT)
{
	if (moveNumber % 2 == 1){ playerTurn = pO; cout << "It is Player One's (" << playerTurn << ") move. Please play: \n"; }
	else if (moveNumber %2 == 0) { playerTurn =pT; cout << "It is Player Two's (" << playerTurn << ") move. Please play: \n"; }
}

void printBoard(char TicTacToe[SIZE][SIZE])

{
	cout << "   |   |   \n " << TicTacToe[0][0] << " | " << TicTacToe[0][1] << " | " << TicTacToe[0][2] << " \n   |   |   \n";
	cout << "---+---+---\n";
	cout << "   |   |   \n " << TicTacToe[1][0] << " | " << TicTacToe[1][1] << " | " << TicTacToe[1][2] << " \n   |   |   \n";
	cout << "---+---+---\n";
	cout << "   |   |   \n " << TicTacToe[2][0] << " | " << TicTacToe[2][1] << " | " << TicTacToe[2][2] << " \n   |   |   \n";
}

void playMove(char playerTurn, char TicTacToe[SIZE][SIZE])
{
	int location = 0, locationX = 0, locationY = 0;
	do{
		cout << "Please enter your location as on NumPad: "; cin >> location;
		setLocation(location, locationX, locationY);
	} while (location < -1 || location>9 || (TicTacToe[locationY][locationX]!=' '));

	TicTacToe[locationY][locationX] = playerTurn;
}

void setLocation(int location, int& locationX, int& locationY){
	if (location == 7){ locationY = 0; locationX = 0; }
	if (location == 8){ locationY = 0; locationX = 1; }
	if (location == 9){ locationY = 0; locationX = 2; }
	if (location == 4){ locationY = 1; locationX = 0; }
	if (location == 5){ locationY = 1; locationX = 1; }
	if (location == 6){ locationY = 1; locationX = 2; }
	if (location == 1){ locationY = 2; locationX = 0; }
	if (location == 2){ locationY = 2; locationX = 1; }
	if (location == 3){ locationY = 2; locationX = 2; } 
}

void checkWinner(char TicTacToe[SIZE][SIZE], char& winner){
		if (TicTacToe[0][0] == TicTacToe[0][1] && TicTacToe[0][1] == TicTacToe[0][2] ||
			TicTacToe[0][0] == TicTacToe[1][0] && TicTacToe[1][0] == TicTacToe[2][0] ||
			TicTacToe[0][0] == TicTacToe[1][1] && TicTacToe[1][1] == TicTacToe[2][2])
			winner = TicTacToe[0][0];
		else if (TicTacToe[1][1] == TicTacToe[0][2] && TicTacToe[0][2] == TicTacToe[2][0] ||
			TicTacToe[0][1] == TicTacToe[1][1] && TicTacToe[1][1] == TicTacToe[2][1] ||
			TicTacToe[1][0] == TicTacToe[1][1] && TicTacToe[1][1] == TicTacToe[1][2])
			winner = TicTacToe[1][1];
		else if (TicTacToe[2][0] == TicTacToe[2][1] && TicTacToe[2][1] == TicTacToe[2][2] ||
			TicTacToe[0][2] == TicTacToe[1][2] && TicTacToe[1][2] == TicTacToe[2][2])
			winner = TicTacToe[2][2];
		else
			winner = ' ';
}
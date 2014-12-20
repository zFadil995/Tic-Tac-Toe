#include <iostream>
using namespace std;

char playerOne, playerTwo, pComp;

void chooseSign();
void printBoard(char TicTacToe[3][3]);
void populateMatrix(char TicTacToe[3][3]);
void printStatus(char MoveToPrint, int MoveNumber);
char checkMove(int moveNumber);
void playMove(char MoveToPrint, char TicTacToe[3][3]);
void checkLocation(char TicTacToe[3][3], int locationX, int locationY, char MoveToPrint);
void checkWinner(char TicTacToe[3][3]);
void PlayerVsPlayer();
void PlayerVsComputer();

void main()
{
	int choice = 0;
	do{
		cout << "Choose: \n1 for a local multipayer game\n2 for a player vs computer game\n"; cin >> choice;
		switch (choice)
		{
		case 1:PlayerVsPlayer(); break;
		case 2:PlayerVsComputer(); break;
		default: break;
		}
	} while (1);
	system("PAUSE");
}

void chooseSign()
{
	do{
		cout << "Choose X or O: "; cin >> playerOne;
		if (playerOne == 'X' || playerOne == 'x')
		{
			playerOne = 'X';
			playerTwo = 'O';
		}
		else if (playerOne == 'O' || playerOne == 'o')
		{
			playerOne = 'O';
			playerTwo = 'X';
		}
		else if (playerOne == '0')
			main();
		else
		{
			cout << "Choose again.\n";
			playerTwo = 'N';
		}
	} while (playerTwo == 'N');
}

void printBoard(char TicTacToe[3][3])
{
	system("CLS");
	cout << "   |   |   \n " << TicTacToe[0][0] << " | " << TicTacToe[0][1] << " | " << TicTacToe[0][2] << " \n   |   |   \n";
	cout << "---+---+---\n";
	cout << "   |   |   \n " << TicTacToe[1][0] << " | " << TicTacToe[1][1] << " | " << TicTacToe[1][2] << " \n   |   |   \n";
	cout << "---+---+---\n";
	cout << "   |   |   \n " << TicTacToe[2][0] << " | " << TicTacToe[2][1] << " | " << TicTacToe[2][2] << " \n   |   |   \n";
}

void populateMatrix(char TicTacToe[3][3])
{
	for (int column = 0; column < 3; column++)
		for (int row = 0; row < 3; row++)
		{
			TicTacToe[column][row] = ' ';
		}
}

void printStatus(char MoveToPrint, int MoveNumber)
{
	if (MoveNumber % 2 == 0)
		cout << "It is Player One's (" << MoveToPrint << ") move. Please play: \n";
	else
		cout << "It is Player Two's (" << MoveToPrint << ") move. Please play: \n";
}

char checkMove(int moveNumber)
{
	char playerMove;
	if (moveNumber % 2 == 0)
		playerMove = playerOne;
	else
		playerMove = playerTwo;
	return playerMove;
}

void playMove(char MoveToPrint, char TicTacToe[3][3])
{
	int location;
	do{
		cout << "Please enter your location as on NumPad: "; cin >> location;
	} while (location < -1 || location>9);
	switch (location)
	{
	case 7:checkLocation(TicTacToe, 0, 0, MoveToPrint); break;
	case 8:checkLocation(TicTacToe, 0, 1, MoveToPrint); break;
	case 9:checkLocation(TicTacToe, 0, 2, MoveToPrint); break;
	case 4:checkLocation(TicTacToe, 1, 0, MoveToPrint); break;
	case 5:checkLocation(TicTacToe, 1, 1, MoveToPrint); break;
	case 6:checkLocation(TicTacToe, 1, 2, MoveToPrint); break;
	case 1:checkLocation(TicTacToe, 2, 0, MoveToPrint); break;
	case 2:checkLocation(TicTacToe, 2, 1, MoveToPrint); break;
	case 3:checkLocation(TicTacToe, 2, 2, MoveToPrint); break;
	case 0:PlayerVsPlayer(); break;
	case -1:main(); break;
	}
}

void checkLocation(char TicTacToe[3][3], int locationY, int locationX, char MoveToPrint)
{
	int a;
	if (TicTacToe[locationY][locationX] == ' ')
		TicTacToe[locationY][locationX] = MoveToPrint;
	else
	{
		cout << "Already taken! ";
		playMove(MoveToPrint, TicTacToe);
	}
}

void checkWinner(char TicTacToe[3][3])
{

}

void PlayerVsPlayer()
{
	char TicTacToe[3][3];
	int moveNumber = 0;
	char moveToPrint;
	chooseSign();
	populateMatrix(TicTacToe);
	do{
		printBoard(TicTacToe);
		moveToPrint = checkMove(moveNumber);
		printStatus(moveToPrint, moveNumber);
		playMove(moveToPrint, TicTacToe);
		printBoard(TicTacToe);
		checkWinner(TicTacToe);
		moveNumber++;
	} while (moveNumber < 9);
}

void PlayerVsComputer()
{
	cout << "In development :)\n";
	cout << "just for a branch :D \n";
}
#include <iostream>
#define size 3
using namespace std;

char choosePlayer()
{
	char player;
	do{
		cout << "Please choose o or x: "; cin >> player;
	} while (player != 'x'&&player != 'o');
	return player;
}
char chooseSign(char player)
{
	char comp;
	if (player == 'x')
		comp = 'o';
	else if (player == 'o')
		comp = 'x';
	return comp;
	system("CLS");
}
char chooseTurn(int a, char p, char c)
{
	char turn;
	if (a % 2 == 0)
		turn = p;
	else
		turn = c;
	return turn;
}
void print(char t[size][size], int SIZE)
{
	system("CLS");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << t[i][j] << "\t";
		}
		cout << endl << endl;
	}
}
char printStatus(char p, char c, char t)
{
	cout << "Player 1: " << p << " Player 2: " << c << endl << "It is " << t << " turn." << endl;
	return t;
}
void change(char t[size][size], int SIZE, char turn)
{
	int x, y, z;
	do{
		do{
			cout << "Choose your y position: "; cin >> y;
		} while (y < 1 || y>3);
		do{
			cout << "Choose your x position: "; cin >> x;
		} while (x < 1 || x>3);
		z = t[y - 1][x - 1];
		t[y - 1][x - 1] = turn;
	} while (z != 'x' && z != 'o');
	
}

void main()
{
	char tac[size][size] = {};
	char player, comp, turn;
	int i = 0;
	player = choosePlayer();
	comp = chooseSign(player);
	while (1)
	{
		turn = chooseTurn(i, player, comp);
		printStatus(player, comp, turn);
		change(tac, size, turn);
		print(tac, size);
		i++;
	}
}
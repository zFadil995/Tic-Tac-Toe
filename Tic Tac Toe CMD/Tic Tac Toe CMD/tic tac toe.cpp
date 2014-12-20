#include <iostream>
using namespace std;

char pOne, pTwo, pCom;

void cSign()
{
	do{
		cout << "Choose X or O: "; cin >> pOne;
		if (pOne == 'X' || pOne == 'x')
			pTwo = 'O';
		else if (pOne == 'O' || pOne == 'o')
			pTwo = 'X';
		else
		{
			cout << "Choose again.\n";
			pTwo = 'N';
		}
	} while (pTwo == 'N');
}

void pvsp()
{
	cSign();
	cout << "\npOne: " << pOne << " & pTwo: " << pTwo << ".\n";
}

void pvsc()
{
	cout << "In development :)\n";
}

void main()
{
	int choice = 0;
	char game = 'y';
	do{
		cout << "Choose: \n1 for a local multipayer game\n2 for a player vs computer game\n"; cin >> choice;
		switch (choice)
		{
		case 1:pvsp(); break;
		case 2:pvsc(); break;
		default: break;
		}
		cout << "Another game? Y/N "; cin >> game;
	} while (game == 'y' || game == 'Y');
	system("PAUSE");
}
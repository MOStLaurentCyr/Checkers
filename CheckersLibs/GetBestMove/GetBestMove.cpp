// GetBestMove.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "../CheckersLibs/Checkers.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int locationX;
	int locationY;
	int moveX;
	int moveY;
	cout << "Enter the X location of the piece" << endl;
	cin >> locationX;
	cout << "Enter the Y location of the piece" << endl;
	cin >> locationY;
	cout << "Enter the X arrival location" << endl;
	cin >> moveX;
	cout << "Enter the Y arrival location" << endl;
	cin >> moveY;

	Checkers checkers = Checkers();
	checkers.move(locationX, locationY, moveX, moveY);
	Move* bestMove = checkers.getBestMove();
	cout << "The best move is: " << bestMove->toString();
}


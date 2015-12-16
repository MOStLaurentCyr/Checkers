#include "stdafx.h"
#include "Checkers.h"

Checkers::Checkers(void)
{
	setInitialPieces();
}

void Checkers::setInitialPieces()
{
	//UpperPieces
	_checkerBoard[0][1] = new Piece(0, 1);
	_checkerBoard[0][3] = new Piece(0, 3);
	_checkerBoard[1][0] = new Piece(1, 0);
	_checkerBoard[1][2] = new Piece(1, 2);
	_checkerBoard[2][1] = new Piece(2, 1);
	_checkerBoard[2][3] = new Piece(2, 3);
	_checkerBoard[3][0] = new Piece(3, 0);
	_checkerBoard[3][2] = new Piece(3, 2);
	_checkerBoard[4][1] = new Piece(4, 1);
	_checkerBoard[4][3] = new Piece(4, 3);
	_checkerBoard[5][0] = new Piece(5, 0);
	_checkerBoard[5][2] = new Piece(5, 2);
	_checkerBoard[6][1] = new Piece(6, 1);
	_checkerBoard[6][3] = new Piece(6, 3);
	_checkerBoard[7][0] = new Piece(7, 0);
	_checkerBoard[7][2] = new Piece(7, 2);
	_checkerBoard[8][1] = new Piece(8, 1);
	_checkerBoard[8][3] = new Piece(8, 3);
	_checkerBoard[9][0] = new Piece(9, 0);
	_checkerBoard[9][2] = new Piece(9, 2);

	//LowerPieces
	_checkerBoard[0][7] = new Piece(0, 7);
	_checkerBoard[0][9] = new Piece(0, 9);
	_checkerBoard[1][6] = new Piece(1, 6);
	_checkerBoard[1][8] = new Piece(1, 8);
	_checkerBoard[2][7] = new Piece(2, 7);
	_checkerBoard[2][9] = new Piece(2, 9);
	_checkerBoard[3][6] = new Piece(3, 6);
	_checkerBoard[3][8] = new Piece(3, 8);
	_checkerBoard[4][7] = new Piece(4, 7);
	_checkerBoard[4][9] = new Piece(4, 9);
	_checkerBoard[5][6] = new Piece(5, 6);
	_checkerBoard[5][8] = new Piece(5, 8);
	_checkerBoard[6][7] = new Piece(6, 7);
	_checkerBoard[6][9] = new Piece(6, 9);
	_checkerBoard[7][6] = new Piece(7, 6);
	_checkerBoard[7][8] = new Piece(7, 8);
	_checkerBoard[8][7] = new Piece(8, 7);
	_checkerBoard[8][9] = new Piece(8, 9);
	_checkerBoard[9][6] = new Piece(9, 6);
	_checkerBoard[9][8] = new Piece(9, 8);
}


Checkers::~Checkers(void)
{
	delete[] _checkerBoard;
}


//Peut-etre a mettre dans c# debut
int Checkers::getPiecePosition(Piece selectedPiece)
{
	return selectedPiece.getLocation();
}

int Checkers::getFuturePiecePosition(Move futurePosition)
{
	return futurePosition.getLocation();
}
//fin

Move* Checkers::getBestMove()
{
	Move* rightMove;
	Move* leftMove;

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(_checkerBoard[i][j]->getType() == 'n')
			{
				rightMove = getRightMove(i, j);

			}
		}
	}
}

int Checkers::getNbPiecesAlive()
{
	int nbPiecesAlive = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (_checkerBoard[i][j]->getType() != 0)
			{
				nbPiecesAlive++;

			}
		}
	}

	return nbPiecesAlive;
}

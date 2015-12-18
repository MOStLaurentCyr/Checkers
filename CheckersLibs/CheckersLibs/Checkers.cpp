#include "stdafx.h"
#include "Checkers.h"

Checkers::Checkers(void)
{
	setInitialBoard();
	setInitialPieces();
}

void Checkers::setInitialBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			_checkerBoard[i][j] = new Piece(0);
		}
	}
}

void Checkers::setInitialPieces()
{
	//UpperPieces (Black)
	_checkerBoard[0][1] = new Piece(2);
	_checkerBoard[0][3] = new Piece(2);
	_checkerBoard[1][0] = new Piece(2);
	_checkerBoard[1][2] = new Piece(2);
	_checkerBoard[2][1] = new Piece(2);
	_checkerBoard[2][3] = new Piece(2);
	_checkerBoard[3][0] = new Piece(2);
	_checkerBoard[3][2] = new Piece(2);
	_checkerBoard[4][1] = new Piece(2);
	_checkerBoard[4][3] = new Piece(2);
	_checkerBoard[5][0] = new Piece(2);
	_checkerBoard[5][2] = new Piece(2);
	_checkerBoard[6][1] = new Piece(2);
	_checkerBoard[6][3] = new Piece(2);
	_checkerBoard[7][0] = new Piece(2);
	_checkerBoard[7][2] = new Piece(2);
	_checkerBoard[8][1] = new Piece(2);
	_checkerBoard[8][3] = new Piece(2);
	_checkerBoard[9][0] = new Piece(2);
	_checkerBoard[9][2] = new Piece(2);

	//LowerPieces (White)
	_checkerBoard[0][7] = new Piece(1);
	_checkerBoard[0][9] = new Piece(1);
	_checkerBoard[1][6] = new Piece(1);
	_checkerBoard[1][8] = new Piece(1);
	_checkerBoard[2][7] = new Piece(1);
	_checkerBoard[2][9] = new Piece(1);
	_checkerBoard[3][6] = new Piece(1);
	_checkerBoard[3][8] = new Piece(1);
	_checkerBoard[4][7] = new Piece(1);
	_checkerBoard[4][9] = new Piece(1);
	_checkerBoard[5][6] = new Piece(1);
	_checkerBoard[5][8] = new Piece(1);
	_checkerBoard[6][7] = new Piece(1);
	_checkerBoard[6][9] = new Piece(1);
	_checkerBoard[7][6] = new Piece(1);
	_checkerBoard[7][8] = new Piece(1);
	_checkerBoard[8][7] = new Piece(1);
	_checkerBoard[8][9] = new Piece(1);
	_checkerBoard[9][6] = new Piece(1);
	_checkerBoard[9][8] = new Piece(1);
	_selectionTree = new SelectionTree(new Move(0,0,0,0,_checkerBoard));
}


Checkers::~Checkers(void)
{
	delete _checkerBoard;
}

Move* Checkers::getBestMove()
{
	return _selectionTree->getBestMove();
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

void Checkers::calculatePossiblesMoves()
{
	int possibleMoves = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (_checkerBoard[i][j]->getType() == 2)//les pieces noires descendent
			{
				if (_checkerBoard[i - 1][j + 1]->getType() == 0)//case bas droite est libre
				{
					setNewPossibleMove(i, j, i - 1, j + 1, _checkerBoard);
				}
				else if (_checkerBoard[i - 1][j + 1]->getType() == 1 && _checkerBoard[i - 2][j + 2]->getType() == 0)
				{
					setNewPossibleMove(i, j, i - 2, j + 2, _checkerBoard);
				}
				if (_checkerBoard[i + 1][j + 1]->getType() == 0)//case bas gauche est libre
				{
					setNewPossibleMove(i, j, i + 1, j + 1, _checkerBoard);
				}
				else if (_checkerBoard[i + 1][j + 1]->getType() == 1 && _checkerBoard[i + 2][j + 2]->getType() == 0)
				{
					setNewPossibleMove(i, j, i + 2, j + 2, _checkerBoard);
				}
				possibleMoves++;
			}
		}
	}
}

void Checkers::move(int locationX, int locationY, int moveX, int moveY)
{
	Piece* temp = _checkerBoard[moveX][moveY];
	_checkerBoard[moveX][moveY] = _checkerBoard[locationX][locationY];
	_checkerBoard[locationX][locationY] = temp;
}

<<<<<<< HEAD
S_checkerBoard* Checkers::getTab()
=======
void Checkers::setNewPossibleMove(int locX, int locY, int moveX, int moveY, Piece* checkerBoard[10][10])
{
	Move* newMove = new Move(locX, locY, moveX, moveY, checkerBoard);
	_selectionTree->add(newMove, _selectionTree->getRoot());
}

Piece*[][10] Checkers::getTab()
>>>>>>> refs/remotes/origin/Ced
{
	return _checkerBoard;
}


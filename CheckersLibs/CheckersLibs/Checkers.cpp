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
			_checkerBoard->_sCheckerBoard[i][j] = new Piece(0);
		}
	}
}

void Checkers::setInitialPieces()
{
	//UpperPieces (Black)
	_checkerBoard->_sCheckerBoard[0][1] = new Piece(2);
	_checkerBoard->_sCheckerBoard[0][3] = new Piece(2);
	_checkerBoard->_sCheckerBoard[1][0] = new Piece(2);
	_checkerBoard->_sCheckerBoard[1][2] = new Piece(2);
	_checkerBoard->_sCheckerBoard[2][1] = new Piece(2);
	_checkerBoard->_sCheckerBoard[2][3] = new Piece(2);
	_checkerBoard->_sCheckerBoard[3][0] = new Piece(2);
	_checkerBoard->_sCheckerBoard[3][2] = new Piece(2);
	_checkerBoard->_sCheckerBoard[4][1] = new Piece(2);
	_checkerBoard->_sCheckerBoard[4][3] = new Piece(2);
	_checkerBoard->_sCheckerBoard[5][0] = new Piece(2);
	_checkerBoard->_sCheckerBoard[5][2] = new Piece(2);
	_checkerBoard->_sCheckerBoard[6][1] = new Piece(2);
	_checkerBoard->_sCheckerBoard[6][3] = new Piece(2);
	_checkerBoard->_sCheckerBoard[7][0] = new Piece(2);
	_checkerBoard->_sCheckerBoard[7][2] = new Piece(2);
	_checkerBoard->_sCheckerBoard[8][1] = new Piece(2);
	_checkerBoard->_sCheckerBoard[8][3] = new Piece(2);
	_checkerBoard->_sCheckerBoard[9][0] = new Piece(2);
	_checkerBoard->_sCheckerBoard[9][2] = new Piece(2);

	//LowerPieces (White)
	_checkerBoard->_sCheckerBoard[0][7] = new Piece(1);
	_checkerBoard->_sCheckerBoard[0][9] = new Piece(1);
	_checkerBoard->_sCheckerBoard[1][6] = new Piece(1);
	_checkerBoard->_sCheckerBoard[1][8] = new Piece(1);
	_checkerBoard->_sCheckerBoard[2][7] = new Piece(1);
	_checkerBoard->_sCheckerBoard[2][9] = new Piece(1);
	_checkerBoard->_sCheckerBoard[3][6] = new Piece(1);
	_checkerBoard->_sCheckerBoard[3][8] = new Piece(1);
	_checkerBoard->_sCheckerBoard[4][7] = new Piece(1);
	_checkerBoard->_sCheckerBoard[4][9] = new Piece(1);
	_checkerBoard->_sCheckerBoard[5][6] = new Piece(1);
	_checkerBoard->_sCheckerBoard[5][8] = new Piece(1);
	_checkerBoard->_sCheckerBoard[6][7] = new Piece(1);
	_checkerBoard->_sCheckerBoard[6][9] = new Piece(1);
	_checkerBoard->_sCheckerBoard[7][6] = new Piece(1);
	_checkerBoard->_sCheckerBoard[7][8] = new Piece(1);
	_checkerBoard->_sCheckerBoard[8][7] = new Piece(1);
	_checkerBoard->_sCheckerBoard[8][9] = new Piece(1);
	_checkerBoard->_sCheckerBoard[9][6] = new Piece(1);
	_checkerBoard->_sCheckerBoard[9][8] = new Piece(1);
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
			if (_checkerBoard->_sCheckerBoard[i][j]->getType() != 0)
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
			if (_checkerBoard->_sCheckerBoard[i][j]->getType() == 2)//les pieces noires descendent
			{
				if (_checkerBoard->_sCheckerBoard[i - 1][j + 1]->getType() == 0)//case bas droite est libre
				{
					setNewPossibleMove(i, j, i - 1, j + 1, _checkerBoard);
				}
				else if (_checkerBoard->_sCheckerBoard[i - 1][j + 1]->getType() == 1 && _checkerBoard->_sCheckerBoard[i - 2][j + 2]->getType() == 0)
				{
					setNewPossibleMove(i, j, i - 2, j + 2, _checkerBoard);
				}
				if (_checkerBoard->_sCheckerBoard[i + 1][j + 1]->getType() == 0)//case bas gauche est libre
				{
					setNewPossibleMove(i, j, i + 1, j + 1, _checkerBoard);
				}
				else if (_checkerBoard->_sCheckerBoard[i + 1][j + 1]->getType() == 1 && _checkerBoard->_sCheckerBoard[i + 2][j + 2]->getType() == 0)
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
	Piece* temp = _checkerBoard->_sCheckerBoard[moveX][moveY];
	_checkerBoard->_sCheckerBoard[moveX][moveY] = _checkerBoard->_sCheckerBoard[locationX][locationY];
	_checkerBoard->_sCheckerBoard[locationX][locationY] = temp;
}

void Checkers::setNewPossibleMove(int locX, int locY, int moveX, int moveY, S_checkerBoard* checkerBoard)
{
	Move* newMove = new Move(locX, locY, moveX, moveY, checkerBoard);
	_selectionTree->add(newMove, _selectionTree->getRoot());
}

S_checkerBoard* Checkers::getTab()
{
	return _checkerBoard;
}
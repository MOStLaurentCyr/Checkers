#include "stdafx.h"
#include "Checkers.h"


Checkers::Checkers()
{
}


Checkers::~Checkers()
{
}

Move* Checkers::getBestMove()
{
	return _selectionTree->getBestMove();
}

void Checkers::move(int locationX, int locationY, int moveX, int moveY)
{
	Piece* temp = _checkerBoard[moveX][moveY];
	_checkerBoard[moveX][moveY] = _checkerBoard[locationX][locationY];
	_checkerBoard[locationX][locationY] = temp;
}



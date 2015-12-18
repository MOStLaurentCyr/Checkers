#include "stdafx.h"
#include "Move.h"
#include "S_checkerBoard.h"


Move::Move(int locationX, int locationY, int moveX, int moveY, S_checkerBoard* tabSituation)
{
	Piece* temp;
	copyTab(tabSituation);
	_tabSituation->_sCheckerBoard[moveX][moveY] = _tabSituation->_sCheckerBoard[locationX][locationY];
	_piece = _tabSituation->_sCheckerBoard[moveX][moveY];
	_tabSituation->_sCheckerBoard[locationX][locationY] = new Piece(0);
	temp = _tabSituation->_sCheckerBoard[locationX][locationY];
	_tabSituation->_sCheckerBoard[locationX][locationY] = temp;
	_newX = moveX;
	_newY = moveY;
	_innitialX = locationX;
	_innitialY = locationY;
}

int Move::getNewX()
{
	return _newX;
}

int Move::getNewY()
{
	return _newY;
}

Move::~Move(void)
{
}

void Move::copyTab(S_checkerBoard* tabToCopy)
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; i++)
		{
			_tabSituation->_sCheckerBoard[i][j] = tabToCopy->_sCheckerBoard[i][j];
		}
	}
}

string Move::toString()
{
	string moveString = _innitialX + ", " + _innitialY;
	moveString = moveString + " to ";
	moveString = moveString + (char) _newX + ", " + (char) _newY;
	return moveString;
}
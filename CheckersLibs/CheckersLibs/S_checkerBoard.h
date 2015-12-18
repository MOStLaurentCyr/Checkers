#pragma once
#include "Piece.h"
class S_checkerBoard
{
public:
	S_checkerBoard(Piece* tab[10][10]);
	~S_checkerBoard(void);
	Piece* _sCheckerBoard[10][10];

private:
	void copyTab(Piece* tabToCopy[10][10]);
};


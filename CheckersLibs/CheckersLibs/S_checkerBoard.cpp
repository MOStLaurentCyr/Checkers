#include "stdafx.h"
#include "S_checkerBoard.h"


S_checkerBoard::S_checkerBoard(Piece* tab[10][10])
{
	copyTab(tab);
}


S_checkerBoard::~S_checkerBoard(void)
{
}

void S_checkerBoard::copyTab(Piece* tabToCopy[10][10])
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; i++)
		{
			_sCheckerBoard[i][j] = tabToCopy[i][j];
		}
	}
}

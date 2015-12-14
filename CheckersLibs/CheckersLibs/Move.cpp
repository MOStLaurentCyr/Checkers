#include "stdafx.h"
#include "Move.h"


Move::Move(int locationX, int locationY, int moveX, int moveY, Piece* tabSituation[10][10])
{
	copyTab(tabSituation);
	_tabSituation[moveX][moveY] = _tabSituation[locationX][locationY];
	_tabSituation[locationX][locationY] = nullptr;
}


Move::~Move(void)
{
}

void Move::copyTab(Piece* tabToCopy[10][10])
{
	for(int i = 0; i<10; i++)
	{
		for(int j = 0; j < 10; i++)
		{
			_tabSituation[i][j] = tabToCopy[i][j];
		}
	}
}
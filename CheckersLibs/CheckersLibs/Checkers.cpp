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

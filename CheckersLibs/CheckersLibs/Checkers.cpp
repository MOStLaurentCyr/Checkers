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

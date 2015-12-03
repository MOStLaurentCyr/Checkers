#include "stdafx.h"
#include "Piece.h"


Piece::Piece(int locationX, int locationY)
{
	_locationX = locationX;
	_locationY = locationY;
}

short Piece::getType()
{
	return 0;
}

Piece::~Piece()
{
}
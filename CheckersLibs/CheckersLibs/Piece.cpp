#include "stdafx.h"
#include "Piece.h"


Piece::Piece(int locationX, int locationY)
{
	_locationX = locationX;
	_locationY = locationY;
}

Piece::~Piece()
{
}

short Piece::getType()
{
	return 0;
}

int Piece::getLocation()
{
	return _locationX, _locationY;
}
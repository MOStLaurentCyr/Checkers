#include "stdafx.h"
#include "Piece.h"


<<<<<<< HEAD
Piece::Piece(int locationX, int locationY)
=======
Piece::Piece(short type)
>>>>>>> refs/remotes/origin/master
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
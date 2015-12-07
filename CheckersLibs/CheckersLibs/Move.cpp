#include "stdafx.h"
#include "Move.h"


Move::Move(int locationX, int locationY)
{
	_locationX = locationX;
	_locationY = locationY;
}

int Move::getLocation()
{
	return _locationX, _locationY;
}

Move::~Move(void)
{
}

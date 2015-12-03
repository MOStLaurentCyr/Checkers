#pragma once
#include "Piece.h"
class Move
{
public:
	Move(int locationX, int locationY);
	~Move(void);
private:
	int _locationX;
	int _locationY;
};


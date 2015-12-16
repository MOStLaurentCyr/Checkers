#include "stdafx.h"
#include "Piece.h"



Piece::Piece(short type)
{
	_type = type;
}

Piece::~Piece()
{
}

short Piece::getType()
{
	return _type;
}
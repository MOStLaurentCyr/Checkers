#pragma once

class Piece
{
public:

	Piece(int locationX, int locationY);
	short getType();
	~Piece();

private:
	int _locationX;
	int _locationY;
	short type;
};


#pragma once

class Piece
{
public:

	Piece(int locationX, int locationY);
	~Piece();
	int getLocation();
	short getType();

private:
	int _locationX;
	int _locationY;
	short type;
};


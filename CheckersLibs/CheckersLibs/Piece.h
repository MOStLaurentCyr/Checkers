#pragma once
class Piece
{
public:
	Piece(short type);
	~Piece(void);
	short getType();

private:

	short type;
};
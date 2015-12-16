#pragma once

class Piece
{
public:
<<<<<<< HEAD

	Piece(int locationX, int locationY);
	~Piece();
	int getLocation();
=======
	Piece(short type);
	~Piece(void);
>>>>>>> refs/remotes/origin/master
	short getType();

private:
	int _locationX;
	int _locationY;
	short type;
};
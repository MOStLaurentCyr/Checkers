#pragma once
#include "Piece.h"

class Move
{
public:
	Move(int locationX, int locationY, int moveX, int moveY, Piece* tabSituation[10][10]);
	~Move(void);
	int getQuality();
	int getNewX();
	int getNewY();

private:
	Piece* _tabSituation[10][10];
	int moveQuality;
	int _newX;
	int _newY;
	void copyTab(Piece* tabToCopy[10][10]);
	Piece* _piece;
};


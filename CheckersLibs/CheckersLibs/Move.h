#pragma once
#include "Piece.h"
class Move
{
public:
	Move(int locationX, int locationY, int moveX, int moveY, Piece* tabSituation[10][10]);
	~Move(void);
	int getQuality();
private:
	Piece* _tabSituation[10][10];
	int moveQuality;
	void copyTab(Piece* tabToCopy[10][10]);
};


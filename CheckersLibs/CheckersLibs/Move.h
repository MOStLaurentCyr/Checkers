#pragma once
#include "Piece.h"
#include <string>
#include "S_checkerBoard.h"
using namespace std;

class Move
{
public:
	Move(int locationX, int locationY, int moveX, int moveY, S_checkerBoard* tabSituation);
	~Move(void);
	int getQuality();
	int getNewX();
	int getNewY();

	string toString(); // for terminal display

private:
	S_checkerBoard* _tabSituation;
	int _moveQuality;
	int _newX;
	int _newY;
	int _innitialX; // for terminal display
	int _innitialY; // for terminal display
	void copyTab(S_checkerBoard* tabToCopy);
	Piece* _piece;
};


#pragma once
#include "Piece.h"
<<<<<<< HEAD

=======
#include <string>
using namespace std;
>>>>>>> refs/remotes/origin/master
class Move
{
public:
	Move(int locationX, int locationY, int moveX, int moveY, Piece* tabSituation[10][10]);
	~Move(void);
	int getQuality();
	int getNewX();
	int getNewY();
<<<<<<< HEAD

=======
	string toString(); // for terminal display
>>>>>>> refs/remotes/origin/master
private:
	Piece* _tabSituation[10][10];
	int _moveQuality;
	int _newX;
	int _newY;
	int _innitialX; // for terminal display
	int _innitialY; // for terminal display
	void copyTab(Piece* tabToCopy[10][10]);
	Piece* _piece;
};


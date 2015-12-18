#pragma once
#include "Move.h"
#include "SelectionTree.h"
#include "Piece.h"
#include "S_checkerBoard.h"

class Checkers
{
private:

	void setInitialBoard();
	void setInitialPieces();
	void setNewPossibleMove(int locX, int locY, int moveX, int moveY, Piece* checkerBoard[10][10]);
	
	Move* checkForForcedMove();
	Move* getRightMove(int i, int j);
	Move* getLeftMove(int i, int j);
	void moveDone(int x, int y);

	SelectionTree* _selectionTree;
	S_checkerBoard* _checkerBoard;
	
public:
	Checkers();
	~Checkers();
	void calculatePossiblesMoves();
	Move* getBestMove();
	Piece ** getCheckerBoard();
	int getNbPiecesAlive();

	void move(int locationX, int locationY, int moveX, int moveY);
	S_checkerBoard* getTab();


};


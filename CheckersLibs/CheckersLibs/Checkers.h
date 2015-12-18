#pragma once
#include "Move.h"
#include "SelectionTree.h"
#include "Piece.h"

class Checkers
{
private:

	void setInitialBoard();
	void setInitialPieces();
	void calculatePossiblesMoves();
	void setNewMove(int locX, int locY, int moveX, int moveY, Piece* checkerBoard[10][10]);
	
	Move* checkForForcedMove();
	Move* getRightMove(int i, int j);
	Move* getLeftMove(int i, int j);
	void moveDone(int x, int y);

	SelectionTree* _selectionTree;
	Piece* _checkerBoard[10][10];
	
public:
	Checkers();
	~Checkers();
	Move* getBestMove();
	Piece ** getCheckerBoard();
	int getNbPiecesAlive();

	void move(int locationX, int locationY, int moveX, int moveY);


};


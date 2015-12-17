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
	
	Move* checkForForcedMove();
	Move* getRightMove(int i, int j);
	Move* getLeftMove(int i, int j);
	void moveDone(int x, int y);

	SelectionTree* _selectionTree;
	Piece* _checkerBoard[10][10];
	
public:
	Checkers();
	~Checkers();
	//int getPiecePosition(Piece selectedPiece);
	//int getFuturePiecePosition(Move futurePosition);
	Move* getBestMove();
<<<<<<< HEAD
	int getNbPiecesAlive();
=======
	MovesList* getPossibleMoves();
	void move(int locationX, int locationY, int moveX, int moveY);
>>>>>>> refs/remotes/origin/master


};


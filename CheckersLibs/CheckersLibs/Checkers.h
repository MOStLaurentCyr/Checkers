#pragma once
#include "Move.h"
#include "SelectionTree.h"
#include "Piece.h"

class Checkers
{
private:
	class MovesList
	{
	private:
		struct  Node
		{
			Move* _content;
			Node* _next;
			Node* _previous;
		};

	public:

		Node* _last;
	};
<<<<<<< HEAD
	void setInitialPieces();
	[]Move* calculatePossiblesMoves();
=======
	Move* calculatePossiblesMoves();
>>>>>>> refs/remotes/origin/master
	Move* checkForForcedMove();
	Move* getRightMove(int i, int j);
	Move* getLeftMove(int i, int j);

	MovesList _posibleMove;
	SelectionTree* _selectionTree;
	Piece* _checkerBoard[10][10];
	
public:
	Checkers();
	~Checkers();
	int getPiecePosition(Piece selectedPiece);
	int getFuturePiecePosition(Move futurePosition);
	Move* getBestMove();
	MovesList* getPossibleMoves();
	int getNbPiecesAlive();


};


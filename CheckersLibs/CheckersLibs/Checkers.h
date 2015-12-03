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
	void setInitialPieces();
	[]Move* calculatePossiblesMoves();
	Move* checkForForcedMove();
	Move* getRightMove(int i, int j);
	Move* getLeftMove(int i, int j);

	MovesList _posibleMove;
	SelectionTree* _selectionTree;
	Piece* _checkerBoard[10][10];
	
public:
	Checkers();
	~Checkers();
	Move* getBestMove();
	MovesList* getPossibleMoves();


};


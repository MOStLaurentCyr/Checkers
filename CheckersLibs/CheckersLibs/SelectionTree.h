#pragma once
#include "Move.h"
class SelectionTree
{
private:
	struct Node
	{
	public:
		Node(Move* move, Node* parent);

		Node* _tabChild[20];
		Node* _parent;
		Move* _move;
		int _nbrOfChilds;
		int getQuality();
	};

	void addBranch(Move* moveToAdd, int currentTabIndex, Node* nodeToFind, Node* actualNode);

	Node* _root;

public:
	SelectionTree(Move* lastMove);
	~SelectionTree();
	void add(Move* moveToAdd, Node* parentNode);
	void resetTree(int x, int y);
	Move* getBestMove();
	void cleanTree(int i, Node* parent);
};
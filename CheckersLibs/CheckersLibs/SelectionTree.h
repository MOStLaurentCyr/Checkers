#pragma once
#include "Move.h"
#include "Node.h"
class SelectionTree
{
private:
	

	void addBranch(Move* moveToAdd, int currentTabIndex, Node* nodeToFind, Node* actualNode);

	Node* _root;

public:

	SelectionTree(Move* lastMove);
	~SelectionTree();
	void add(Move* moveToAdd, Node* parentNode);
	void remove(Node* node);
	void resetTree(int x, int y);
	Move* getBestMove();
	void cleanTree(int i, Node* parent);
};


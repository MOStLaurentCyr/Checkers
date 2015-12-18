#pragma once
#include "Move.h"
#include "Node.h"

class SelectionTree
{
private:
	
	void addBranch(Move* moveToAdd, int currentTabIndex, Node* nodeToFind, Node* actualNode);
	void remove(Node* node);
	void cleanTree(int i, Node* parent);
	Node* _root;

public:

	SelectionTree(Move* lastMove);
	~SelectionTree();
	void add(Move* moveToAdd, Node* parentNode);
	void resetTree(int x, int y);
	Move* getBestMove();
<<<<<<< HEAD
	void cleanTree(int i, Node* parent);
};
=======
	Node* getRoot();
};
>>>>>>> refs/remotes/origin/Ced

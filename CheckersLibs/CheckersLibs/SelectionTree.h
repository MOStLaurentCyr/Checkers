#pragma once
#include "Move.h"
class SelectionTree
{
public:
	SelectionTree(Piece* tabCheckers[10][10]);
	~SelectionTree();
	void add();
private: 
	struct Node
	{
	public:
		Node(Piece* tabCheckers);

		Node* tabChild[20];
		Node* parent;
		Piece* situation[10][10];
	};

	Node* root;

};


#include "stdafx.h"
#include "SelectionTree.h"


SelectionTree::SelectionTree(Piece* tabCheckers[10][10])
{
	root = new Node(tabCheckers[10][10]);
}


SelectionTree::~SelectionTree(void)
{
}
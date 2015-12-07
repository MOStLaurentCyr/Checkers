#include "stdafx.h"
#include "SelectionTree.h"


SelectionTree::SelectionTree(Move* lastMove)
{
	_root = new Node(lastMove, nullptr);
}


SelectionTree::~SelectionTree()
{
}

void SelectionTree::add(Move* moveToAdd, SelectionTree::Node* parentNode)
{
	if(_root == nullptr)
	{
		_root = new Node(moveToAdd, nullptr);
	}
	else if(_root == parentNode)
	{
		bool nodeAdded = false;
		for(int i = 0; i < _root->nbrOfChilds; i++)
		{
			if(_root->_tabChild[i] == nullptr)
			{
				_root->_tabChild[i] = new Node(moveToAdd, _root);
				_root->nbrOfChilds++;
				nodeAdded = true;
			}
		}
		
		if(nodeAdded == false)
		{
			Move* temp[40];
		}
	}
	else
	{
		addBranch(moveToAdd, 0, parentNode, _root);
	}
}

void SelectionTree::addBranch(Move* moveToAdd, int index, SelectionTree::Node* nodeToFind, SelectionTree::Node* currentNode)
{

}

SelectionTree::Node::Node(Move* element, SelectionTree::Node* parent)
{

}
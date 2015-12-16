#include "stdafx.h"
#include "SelectionTree.h"


SelectionTree::SelectionTree(Move* lastMove)
{
	_root = new Node(lastMove, nullptr);
}


SelectionTree::~SelectionTree()
{
	remove(_root);
	delete[] _root->_tabChild;
}

void SelectionTree::add(Move* moveToAdd, SelectionTree::Node* parentNode)
{
	if(_root == nullptr)
	{
		_root = new Node(moveToAdd, nullptr);
	}
	else if(_root == parentNode)
	{
		for(int i = 0; i < _root->_nbrOfChilds - 1; i++)
		{
			if(_root->_tabChild[i] == nullptr)
			{
				_root->_tabChild[i] = new Node(moveToAdd, _root);
				_root->_nbrOfChilds++;
			}
		}
	}
	else
	{
		addBranch(moveToAdd, 0, parentNode, _root);
	}
}

void SelectionTree::remove(Node* node)
{
	int compteur = 0;
	while(node != nullptr)
	{
		remove(node->_tabChild[compteur]);
		compteur++;
		delete node;
	}
}

void SelectionTree::addBranch(Move* moveToAdd, int index, SelectionTree::Node* nodeToFind, SelectionTree::Node* currentNode)
{

}

SelectionTree::Node::Node(Move* element, SelectionTree::Node* parent)
{

}
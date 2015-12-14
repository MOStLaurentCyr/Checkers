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
		for(int i = 0; i < _root->_nbrOfChilds; i++)
		{
			if(_root->_tabChild[i] == nullptr)
			{
				_root->_tabChild[i] = new Node(moveToAdd, _root);
				_root->_nbrOfChilds++;
				nodeAdded = true;
			}
		}
		
		if(nodeAdded == false)
		{

		}
	}
	else
	{
		addBranch(moveToAdd, 0, parentNode, _root);
	}
}

void SelectionTree::addBranch(Move* moveToAdd, int currentTabIndex, SelectionTree::Node* nodeToFind, SelectionTree::Node* currentNode)
{
	if(currentNode != nodeToFind)
	{
		if(currentNode->_tabChild[currentTabIndex] == nullptr)
		{
			addBranch(moveToAdd, currentTabIndex++, nodeToFind, currentNode->_parent);
		}
		else
		{
			addBranch(moveToAdd, currentTabIndex, nodeToFind, currentNode->_tabChild[currentTabIndex]);
		}
	}
	else
	{
		bool nodeAdded = false;
		for(int i = 0; i < _root->_nbrOfChilds; i++)
		{
			if(_root->_tabChild[i] == nullptr)
			{
				_root->_tabChild[i] = new Node(moveToAdd, _root);
				_root->_nbrOfChilds++;
				nodeAdded = true;
			}
		}
		
		if(nodeAdded == false)
		{
			
		}
	}
}

SelectionTree::Node::Node(Move* element, SelectionTree::Node* parent)
{

}

Move* SelectionTree::getBestMove()
{
	Move* bestMove = nullptr;
	int bestScore = 0;
	for(int i = 0; i < _root->_nbrOfChilds; i++)
	{
		if(bestMove == nullptr)
		{
			bestMove = _root->_tabChild[i]->_move;
			bestScore = bestMove->getQuality();
		}
		else if(_root->_tabChild[i]->_move->getQuality() > bestScore)
		{
			bestMove = _root->_tabChild[i]->_move;
			bestScore = bestMove->getQuality();
		}
	}
	return bestMove;
}
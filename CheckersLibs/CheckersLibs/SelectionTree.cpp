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
	int bestMoveQuality = 0;
	for(int i = 0; i < _root->_nbrOfChilds; i++)
	{
		if(bestMove == nullptr)
		{
			bestMove = _root->_tabChild[i]->_move;
			bestMoveQuality = _root->_tabChild[i]->getQuality();
		}
		else
		{
			int currentMoveQuality = _root->_tabChild[i]->getQuality();

			if(currentMoveQuality > bestMoveQuality)
			{
				bestMove = _root->_tabChild[i]->_move;
				bestMoveQuality = currentMoveQuality;
			}
		}
	}
	return bestMove;
}

int SelectionTree::Node::getQuality()
{
	int moveQuality = 0;
	if(_nbrOfChilds != 0)
	{
		int childQuality;
		for(int j = 0; j < _nbrOfChilds; j++)
		{
			childQuality = _tabChild[j]->getQuality();
			if(childQuality > moveQuality)
			{
				moveQuality = childQuality;
			}
		}
	}
	else
	{
		moveQuality = _move->getQuality();
	}

	return moveQuality;
}

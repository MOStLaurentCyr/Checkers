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

void SelectionTree::add(Move* moveToAdd, Node* parentNode)
{
	if(_root == parentNode)
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

Node* SelectionTree::getRoot()
{
	return _root;
}


void SelectionTree::remove(Node* node)
{
	int compteur = 0;
	while (node != nullptr)
	{
		remove(node->_tabChild[compteur]);
		compteur++;
		delete node;
	}
}


void SelectionTree::resetTree(int x, int y)
{
	int indexNewRoot;
	for(int i = 0; i < _root->_nbrOfChilds; i++)
	{
		if(x != _root->_tabChild[i]->_move->getNewX() && y != _root->_tabChild[i]->_move->getNewY())
		{
			cleanTree(i, _root);
		}
		else
		{
			indexNewRoot = i;
		}
	}
	Node* temp = _root;
	_root = _root->_tabChild[indexNewRoot];
	delete temp;
}

void SelectionTree::cleanTree(int i, Node* parent)
{
	for(int j = 0; j < parent->_nbrOfChilds; j++)
	{
		cleanTree(j, parent->_tabChild[j]);
	}
	
	delete parent;
}

void SelectionTree::addBranch(Move* moveToAdd, int currentTabIndex, Node* nodeToFind, Node* currentNode)
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
		for(int i = 0; i < _root->_nbrOfChilds; i++)
		{
			if(_root->_tabChild[i] == nullptr)
			{
				_root->_tabChild[i] = new Node(moveToAdd, _root);
				_root->_nbrOfChilds++;
			}
		}
	}
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
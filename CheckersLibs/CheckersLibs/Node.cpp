#include "stdafx.h"
#include "Node.h"


Node::Node(Move* element, Node* parent)
{
	_move = element;
	_parent = parent;
}


Node::~Node(void)
{
}

int Node::getQuality()
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
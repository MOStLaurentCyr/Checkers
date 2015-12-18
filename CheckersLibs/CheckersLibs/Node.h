#pragma once
#include "Move.h"
struct Node
	{
	public:
		Node(Move* move, Node* parent);
		Node::~Node();
		Node* _tabChild[20];
		Node* _parent;
		Move* _move;
		int _nbrOfChilds;
		int getQuality();
	};

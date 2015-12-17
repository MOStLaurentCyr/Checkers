#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(TestSelectionTree)
	{
	public:
		
		TEST_METHOD(SelectionTreeTest)
		{
			Piece* tab[10][10];
			tab[0][0] = new Piece((short) 1);
			SelectionTree* selectionTree = new SelectionTree(new Move(0,0,0,0, tab));
		}

	};
}
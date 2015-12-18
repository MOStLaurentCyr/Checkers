#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CheckersLibs/SelectionTree.h"
#include "../CheckersLibs/Checkers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(TestSelectionTree)
	{
	public:

		TEST_METHOD(_root_from_add_is_equal_to_parent) // a tester addbranch, clean, remove, getbestmove, getquality
		{
			//Arrange
			const int NB_CHILD = 1;
			const int TAB_SIZE = 10;
			short EMPTY_TYPE = 0; // case du damier vide
			short WHITE_TYPE = 1;
			short BLACK_TYPE = 2;

			Piece* tab[TAB_SIZE][TAB_SIZE];
			for (int i = 0; i < TAB_SIZE; i++)
			{
				for (int j = 0; j < TAB_SIZE; j++)
				{
					tab[i][j] = new Piece(EMPTY_TYPE);
				}
			}
			tab[1][0] = new Piece(BLACK_TYPE);
			tab[2][1] = new Piece(WHITE_TYPE);
			tab[3][2] = new Piece(WHITE_TYPE);

			SelectionTree* tree = new SelectionTree(new Move(0, 0, 0, 0, tab));
			Move* move = new Move(1, 0, 2, 1, tab);

			//Act
			tree->add(move, tree->getRoot());


			//Assert
			Assert::AreEqual(NB_CHILD, tree->getRoot()->_nbrOfChilds);
		}

		TEST_METHOD(_root_from_add_is_not_equal_to_parent)
		{
			//Arrange
			const int NB_CHILD = 1;
			const int TAB_SIZE = 10;
			short EMPTY_TYPE = 0; // case du damier vide
			short WHITE_TYPE = 1;
			short BLACK_TYPE = 2;

			Piece* tab[TAB_SIZE][TAB_SIZE];
			for (int i = 0; i < TAB_SIZE; i++)
			{
				for (int j = 0; j < TAB_SIZE; j++)
				{
					tab[i][j] = new Piece(EMPTY_TYPE);
				}
			}
			tab[1][0] = new Piece(BLACK_TYPE);
			tab[2][1] = new Piece(WHITE_TYPE);
			tab[3][2] = new Piece(WHITE_TYPE);

			SelectionTree* tree = new SelectionTree(new Move(0, 0, 0, 0, tab));
			Move* moveToRight= new Move(1, 0, 2, 1, tab);
			Move* moveToLeft = new Move(1, 0, 0, 1, tab);

			//Act
			tree->add(moveToRight, tree->getRoot());
			Node* rightRootBranch = tree->getRoot();
			tree->add(moveToLeft, tree->getRoot());
			Node* leftRootBranch = tree->getRoot();


			//Assert
			Assert::AreNotEqual(leftRootBranch, rightRootBranch);
		}
	};
}
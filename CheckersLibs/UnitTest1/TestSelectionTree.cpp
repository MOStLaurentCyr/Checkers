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

		TEST_METHOD(_root_from_add_is_equal_to_parent)
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

			SelectionTree* tree = new SelectionTree(new Move(0, 0, 0, 0, new S_checkerBoard(tab)));
			Move* move = new Move(1, 0, 2, 1, new S_checkerBoard(tab));

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
			short EMPTY_TYPE = 0; 
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

			SelectionTree* tree = new SelectionTree(new Move(0, 0, 0, 0, new S_checkerBoard(tab)));
			Move* moveToRight= new Move(1, 0, 2, 1,new S_checkerBoard(tab));
			Move* moveToLeft = new Move(1, 0, 0, 1, new S_checkerBoard(tab));

			//Act
			tree->add(moveToRight, tree->getRoot());
			Node* rightRootBranch = tree->getRoot();
			tree->add(moveToLeft, tree->getRoot());
			Node* leftRootBranch = tree->getRoot();


			//Assert
			Assert::AreNotEqual(leftRootBranch, rightRootBranch);
		}

		TEST_METHOD(remove_correctly_destroys_all_the_tree_even_the_root)
		{
			//Arrange
			const int NB_CHILD = 1;
			const int TAB_SIZE = 10;
			Node* ROOT_IS_NULL = nullptr;
			short EMPTY_TYPE = 0; 
			short WHITE_TYPE = 1;
			short BLACK_TYPE = 2;
			Checkers* checkerBoard;
			SelectionTree* tree = new SelectionTree(new Move(0, 0, 0, 0, checkerBoard->getTab()));

			//Act
			checkerBoard->calculatePossiblesMoves();
			tree->~SelectionTree(); // appel du destructeur, car remove est privée, si remove est publique remove(tree->getRoot());

			//Assert
			Assert::AreEqual(ROOT_IS_NULL, tree->getRoot());
		}

		TEST_METHOD(cleanTree_correctly_destroys_the_non_used_branches_of_the_tree)
		{
			//Arrange
			int NB_CHILD_BEFORE_CLEANING_TREE;
			int NB_CHILD_AFTER_CLEANING_TREE;
			const int NB_CHILD = 1;
			const int TAB_SIZE = 10;
			Node* ROOT_IS_NULL = nullptr;
			short EMPTY_TYPE = 0; 
			short WHITE_TYPE = 1;
			short BLACK_TYPE = 2;
			Checkers* checkerBoard;
			checkerBoard->move(1, 6, 3, 4);
			SelectionTree* tree = new SelectionTree(new Move(0, 0, 0, 0, checkerBoard->getTab()));

			//Act
			checkerBoard->calculatePossiblesMoves();
			NB_CHILD_BEFORE_CLEANING_TREE = tree->getRoot()->_nbrOfChilds;
			tree->getBestMove();
			tree->resetTree(tree->getBestMove()->getNewX(), tree->getBestMove()->getNewY());
			NB_CHILD_AFTER_CLEANING_TREE = tree->getRoot()->_nbrOfChilds;

			//Assert
			Assert::AreNotEqual(NB_CHILD_BEFORE_CLEANING_TREE, NB_CHILD_AFTER_CLEANING_TREE);
		}

		TEST_METHOD(getQuality_does_not_return_the_same_quality_if_there_is_no_child_in_tabChild_then_if_there_is)
		{
			//Arrange
			int QUALITY_WITHOUT_CHILD;
			int QUALITY_WITH_CHILD;
			const int NB_CHILD = 1;
			const int TAB_SIZE = 10;
			Node* ROOT_IS_NULL = nullptr;
			short EMPTY_TYPE = 0; 
			short WHITE_TYPE = 1;
			short BLACK_TYPE = 2;
			Checkers* checkerBoard;
			checkerBoard->move(1, 6, 3, 4);
			SelectionTree* tree = new SelectionTree(new Move(0, 0, 0, 0, checkerBoard->getTab()));

			//Act
			QUALITY_WITHOUT_CHILD = tree->getRoot()->_nbrOfChilds;
			checkerBoard->calculatePossiblesMoves();
			QUALITY_WITH_CHILD = tree->getRoot()->_nbrOfChilds;

			//Assert
			Assert::AreNotEqual(QUALITY_WITHOUT_CHILD, QUALITY_WITH_CHILD);
		}
	};
}
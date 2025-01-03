#include "Menu.h"
#include "GetInput.h"
#include "BinaryMenu.h"
#include "TreapMenu.h"
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "Treap.h"
#include "TreapNode.h"
#include <iostream>

using namespace std;

void Menu()
{
	BinaryTree* tree = CreateTree();
	Treap* treap = CreateTreap();
	while (true)
	{
		int choice = GetInput("Menu: \n 1. Binary tree\n 2. Treap\n 0. Exit\n Ypur Input: ");
		switch (choice)
		{
				//TODO:
			case 1:
			{
				BinaryMenu(tree);
				break;
			}

			case 2:
			{
				TreapMenu(treap);
				break;
			}

			case 0:
				return;
			default:
				cout << "Error" << endl;
		}
	}
}
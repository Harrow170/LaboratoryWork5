#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "BinaryMenu.h"
#include "GetInput.h"
#include <iostream>

using namespace std;

void InOrder(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	InOrder(node->Left);
	cout << node->Data << " ";
	InOrder(node->Right);
}

void DisplayTree(const BinaryTree& tree)
{
	InOrder(tree.Root);
}

void BinaryMenu(BinaryTree& tree)
{
	while (true)
	{
		cout << "Current tree: " << endl;
		DisplayTree(tree);
		cout << endl;
		int choice = GetInput("Tree menu: \n 1. Add\n 2. Remove\n 3. Search\n 4. Max\n \
5. Min\n 0. Exit\n Your Input; ");
		switch (choice)
		{
		case 1:
		{
			int value = GetInput("Enter value to add; ");
			Add(tree.Root, value);
			break;
		}

		case 2:
		{
			int value = GetInput("Enter value to remove: ");
			tree.Root = Remove(tree.Root);
			break;
		}

		case 3:
		{
			int value = GetInput("Enter value to search: ");
			if (Search(tree.Root, value))
			{
				cout << "Node found" << endl;
			}

			else
			{
				cout << "Node not found" << endl;
			}

			break;
		}

		case 4:
		{
			BinaryTreeNode* maxNode = SearchMax(tree.Root);
			if (maxNode)
			{
				cout << "Max node: " << maxNode->Data << endl;
			}

			else
			{
				cout << "Empty" << endl;
			}

			break;
		}

		case 5:
		{
			BinaryTreeNode* minNode = SearchMin(tree.Root);
			if (minNode)
			{
				cout << "Min node: " << minNode->Data << endl;
			}

			else
			{
				cout << "Empty" << endl;
			}

			break;
		}

		case 6:
		{
			cout << "Count of nodes: " << GetCount(tree.Root) << endl;
			break;
		}

		case 0:
			Free(tree.Root);
			return;
		default:
			cout << "error" << endl;
		}
	}
}
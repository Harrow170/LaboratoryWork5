#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "BinaryMenu.h"
#include "GetInput.h"
#include <iostream>
#include <string>
#include <exception>
#include <iomanip>

using namespace std;

void DisplayTree(BinaryTreeNode* node, int indent)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->Right)
	{
		DisplayTree(node->Right, indent + 4);
	}

	if (indent)
	{
		cout << setw(indent) << ' ';
	}

	if (node->Right)
	{
		cout << " /\n" << setw(indent) << ' ';
	}

	cout << node->Data << endl;
	if (node->Left)
	{
		cout << setw(indent) << ' ' << "\\\n";
		DisplayTree(node->Left, indent + 4);
	}
}

void BinaryMenu(BinaryTree* tree)
{
	while (true)
	{
		DisplayTree(tree->Root, 1);
		int choice = GetInput("Tree menu: \n 1. Add\n 2. Remove\n 3. Search\n 4. Max\n \
5. Min\n 0. Exit\n Your Input; ");
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter value to add; ");
				Add(tree, value);
				break;
			}

			case 2:
			{
				int value = GetInput("Enter value to remove: ");
				Remove(tree, value);
				break;
			}

			case 3:
			{
				int value = GetInput("Enter value to search: ");
				if (Search(tree, value))
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
				BinaryTree* max = SearchMax(tree);
				if (max)
				{
					cout << "Max node: " << max << endl;
				}

				else
				{
					cout << "Empty" << endl;
				}

				break;
			}

			case 5:
			{
				BinaryTree* min = SearchMin(tree);
				if (min)
				{
					cout << "Min node: " << min << endl;
				}

				else
				{
					cout << "Empty" << endl;
				}

				break;
			}

			case 6:
			{
				cout << "Count of nodes: " << GetCount(tree->Root) << endl;
				break;
			}

			case 0:
				Free(tree->Root);
				return;
			default:
				cout << "error" << endl;
		}
	}
}
#include "Treap.h"
#include "TreapNode.h"
#include "TreapMenu.h"
#include "GetInput.h"
#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include "Space.h"

using namespace std;

void DisplayTreap(TreapNode* node, int indent)
{
	//const int space = 4;
	if (node == nullptr)
	{
		return;
	}

	if (node->Right)
	{
		//TODO: const
		DisplayTreap(node->Right, indent + Space);
	}

	if (indent)
	{
		cout << setw(indent) << ' ';
	}

	if (node->Right)
	{
		cout << " /\n" << setw(indent) << ' ';
	}

	cout << node->Key << "(" << node->Priority << ")" << endl;
	if (node->Left)
	{
		cout << setw(indent) << ' ' << " \\\n";
		DisplayTreap(node->Left, indent + Space);
	}
}

void TreapMenu(Treap* treap)
{
	//Treap* treap = CreateTreap();
	while (true)
	{
		cout << "Current treap: " << endl;
		DisplayTreap(treap->Root, 1);
		cout << endl;
		int choice = GetInput("Treap menu: \n 1. AddO\n 2. AddUO\n 3. RemoveO\n \
4. RemoveUO\n 5. Search\n 6/ Split\n 7. merge\n 0. Exit\n Your Input: ");
		switch (choice)
		{
			case 1:
			{
				int value = GetInput("Enter value to add: ");
				InsertOptimized(treap, value);
				break;
			}

			case 2:
			{
				int value = GetInput("Enter value to Add: ");
				InsertUnoptimized(treap, value);
				break;
			}

			case 3:
			{
				int key = GetInput("Enter value to remove: ");
				if (Find(treap, key))
				{
					DeleteOptimized(treap, key);
				}
				else
				{
					cout << "Try again " << endl;
				}

				break;
			}

			case 4:
			{
				int value = GetInput("Enter value to remove: ");
				if (Find(treap, value))
				{
					DeleteUnoptimized(treap, value);
				}
				else
				{
					cout << "Try again " << endl;
				}
				break;
			}

			case 5:
			{
				int value = GetInput("Enter value to find: ");
				if (Find(treap, value) != nullptr)
				{
					cout << "Value: " << value << endl;
				}

				else
				{
					cout << "not found" << endl;
				}

				break;
			}

			case 6:
			{
				int key = GetInput("Enter key to split: ");
				Split(treap->Root, key, treap->Root->Left, treap->Root->Right);
				break;
			}

			case 7:
			{
				Merge(treap->Root->Left, treap->Root->Right);
				break;
			}

			case 0:
				FreeTreap(treap->Root);
				FreeTreapWrapper(treap);
				return;
			default:
				cout << "Error" << endl;
		}
	}
}
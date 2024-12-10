#include "Treap.h"
#include "TreapNode.h"
#include "TreapMenu.h"
#include "GetInput.h"
#include <iostream>

using namespace std;

void DisplayTreap(TreapNode* node)
{
	if (node != nullptr)
	{
		DisplayTreap(node->Left);
		cout << node->Key << " ";
		DisplayTreap(node->Right);
	}
}

void DisplayTreapWrapper(Treap* treap)
{
	DisplayTreap(treap->Root);
	cout << endl;
}

void TreapMenu(Treap* treap)
{
	while (true)
	{
		cout << "Current treap: " << endl;
		DisplayTreap(treap->Root);
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
				int value = GetInput("Enter value to remove: ");
				DeleteOptimized(treap, value);
				break;
			}

			case 4:
			{
				int value = GetInput("Enter value to remove: ");
				DeleteUnoptimized(treap, value);
				break;
			}

			case 5:
			{
				int value = GetInput("Enter value to find: ");
				if (Find(treap->Root, value) != nullptr)
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
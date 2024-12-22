#include "Treap.h"
#include "TreapNode.h"

Treap* CreateTreap()
{
	Treap* treap = new Treap();
	treap->Root = nullptr;
	return treap;
	//return new Treap;
}

TreapNode* Find(Treap* treap, int value)
{
	TreapNode* current = treap->Root;
	while (current != nullptr)
	{
		if (current->Key == value)
		{
			return current;
		}

		else if (value < current->Key)
		{
			current = current->Left;
		}

		else
		{
			current = current->Right;
		}
	}

	return nullptr;
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}

	else if (node->Key <= key)
	{
		left = node;
		Split(node->Right, key, node->Right, right);
	}

	else //if (node->Key <= key)
	{
		right = node;
		Split(node->Left, key, left, node->Left);
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}

	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

void InsertUnoptimized(Treap* treap, int key)
{
	TreapNode* newNode = CreateTreapNode(key);
	if (treap->Root == nullptr)
	{
		treap->Root = newNode;
		return;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	treap->Root = Merge(Merge(left, newNode), right);
	//return treap;
}

void InsertOptimized(Treap* treap, int key)
{
	TreapNode* newNode = CreateTreapNode(key);
	if(treap->Root == nullptr)
	{
		treap->Root = newNode;
		return;
	}

	if (newNode->Priority > treap->Root->Priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(treap->Root, key, left, right);
		newNode->Left = left;
		newNode->Right = right;
		treap->Root = newNode;
		return;
	}

	TreapNode* current = treap->Root;
	TreapNode* parent = nullptr;
	while (current != nullptr)
	{
		parent = current;
		if (key < current->Key)
		{
			current = current->Left;
		}

		else
		{
			current = current->Right;
		}
	}

	if (key < parent->Key)
	{
		parent->Left = newNode;
	}

	else
	{
		parent->Right = newNode;
	}

	//return treap;
}

void DeleteUnoptimized(Treap* treap, int key)
{
	if (treap->Root == nullptr)
	{
		return;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	TreapNode* mid = nullptr;
	Split(treap->Root, key, left, right);
	Split(right, key + 1, mid, right);
	if (mid)
	{
		delete mid;
		treap->Root = Merge(left, right);
	}

	else
	{
		treap->Root = Merge(left, mid);
	}
}

void DeleteOptimized(Treap* treap, int key)
{
	TreapNode* nodeToDelete = Find(treap, key);
	if (treap->Root == nullptr)
	{
		return;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	delete nodeToDelete;
	treap->Root = Merge(left, right);
}

void FreeTreap(TreapNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	FreeTreap(node->Left);
	FreeTreap(node->Right);
	delete node;
}

void FreeTreapWrapper(Treap*& treap)
{
	FreeTreap(treap->Root);
	delete treap;
}
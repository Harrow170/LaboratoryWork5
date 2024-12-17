#include "Treap.h"
#include "TreapNode.h"

Treap* CreateTreap()
{
	return new Treap;
}

TreapNode* Find(TreapNode* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Key == value)
	{
		return node;
	}

	if (node->Key > value)
	{
		return Find(node->Left, value);
	}

	else
	{
		return Find(node->Right, value);
	}
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}

	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}

	else //if (node->Key <= key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr)
	{
		return left;
	}

	if (right == nullptr)
	{
		return right;
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

void InsertUnoptimized(Treap*& treap, int key)
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
}

void InsertOptimized(Treap*& treap, int key)
{
	TreapNode* newNode = CreateTreapNode(key);
	if(treap->Root == nullptr)
	{
		treap->Root = newNode;
		return;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	newNode->Left = left;
	newNode->Right = right;
	treap->Root = newNode;
}

void DeleteUnoptimized(Treap*& treap, int key)
{
	if (treap->Root == nullptr)
	{
		return;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	
	TreapNode* midLeft = nullptr;
	TreapNode* midRight = nullptr;
	Split(left, key - 1, midLeft, midRight);

	treap->Root = Merge(midLeft, right);
	delete midRight;
}

void DeleteOptimized(Treap*& treap, int key)
{
	TreapNode* nodeToDelete = Find(treap->Root, key);
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
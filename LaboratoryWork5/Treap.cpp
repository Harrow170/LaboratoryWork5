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
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}

	right->Left = Merge(left, right->Left);
	return right;
}

void Insert1Way(Treap* treap, int key)
{
	TreapNode* newNode = new TreapNode(key);
	if (treap->Root == nullptr)
	{
		treap->Root = newNode;
		return;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	if (newNode->Priority > (left ? left->Priority : 0))
	{
		newNode->Left = left;
		newNode->Right = right;
		treap->Root = newNode;
	}

	else
	{
		if (key <= left->Key)
		{
			left->Left = Insert1Way(left->Left, key);
		}

		else
		{
			left->Right = Insert1Way(left->Right, key);
		}

		treap->Root = Merge(left, right);
	}
}

void Insert2Way(Treap* treap, int key)
{
	TreapNode* newNode = new TreapNode(key);
	if (treap->Root == nullptr)
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

void Delete1Way(Treap* treap, int key)
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

void Delete2Way(Treap* treap, int key)
{
	if (treap->Root == nullptr)
	{
		return;
	}

	if (treap->Root->Key == key)
	{
		TreapNode* temp = Merge(treap->Root->Left, treap->Root->Right);
		delete treap->Root;
		treap->Root = temp;
		return;
	}

	if (key < treap->Root->Key)
	{
		Delete2Way(treap->Root->Left, key);
	}

	else
	{
		Delete2Way(treap->Root->Right, key);
	}
}
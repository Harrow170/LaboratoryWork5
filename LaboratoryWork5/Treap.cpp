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

Treap* InsertUnoptimized(Treap* treap, int key)
{
	TreapNode* newNode = CreateTreapNode(key);
	if (treap->Root == nullptr)
	{
		treap->Root = newNode;
		return treap;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	treap->Root = Merge(Merge(left, newNode), right);
	return treap;
}

Treap* InsertOptimized(Treap* treap, int key)
{
	TreapNode* newNode = CreateTreapNode(key);
	if(treap->Root == nullptr)
	{
		treap->Root = newNode;
		return treap;
	}

	if (newNode->Priority > treap->Root->Priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(treap->Root, key, left, right);
		newNode->Left = left;
		newNode->Right = right;
		treap->Root = newNode;
		return treap;
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

	return treap;
}

Treap* DeleteUnoptimized(Treap* treap, int key)
{
	if (treap->Root == nullptr)
	{
		return treap;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	TreapNode* midLeft = nullptr;
	TreapNode* midRight = nullptr;
	Split(left, key - 1, midLeft, midRight);
	if (midRight != nullptr)
	{
		delete midRight;
	}

	treap->Root = Merge(midLeft, right);

	return treap;
}

Treap* DeleteOptimized(Treap* treap, int key)
{
	if (treap->Root == nullptr)
	{
		return treap;
	}

	TreapNode* current = treap->Root;
	TreapNode* parent = nullptr;
	while (current != nullptr && current->Key != key)
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

	if (current == nullptr)
	{
		return treap;
	}

	TreapNode* leftChild = current->Left;
	TreapNode* rightChild = current->Right;
	TreapNode* mergedChild = Merge(leftChild, rightChild);
	if (current == treap->Root)
	{
		treap->Root = mergedChild;
	}

	else
	{
		if (parent->Left == current)
		{
			parent->Left = mergedChild;
		}
		else
		{
			parent->Right = mergedChild;
		}
	}

	delete current;
	return treap;
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
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
//#include "BinaryTree.h"

BinaryTree* CreateTree()
{
	return new BinaryTree();
}

void Add(BinaryTreeNode*& node, int value)
{
	if (node == nullptr)
	{
		node = new BinaryTreeNode(value);
		return;
	}

	if (node->Data > value)
	{
		Add(node->Left, value);
	}

	else
	{
		Add(node->Right, value);
	}
}

BinaryTreeNode* Remove(BinaryTreeNode*& node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (node->Data > value)
	{
		node->Left = Remove(node->Left, value);
	}

	else if (value > node->Data)
	{
		node->Right = Remove(node->Right, value);
	}

	else
	{
		if (node->Left == nullptr)
		{
			BinaryTreeNode* temp = node->Right;
			delete node;
			delete temp;
		}

		else if (node->Right == nullptr)
		{
			BinaryTreeNode* temp = node->Left;
			delete node;
			delete temp;
		}

		BinaryTreeNode* temp = SearchMin(node->Right);
		node->Data = temp->Data;
		node->Right = Remove(node->Right, temp->Data);
	}

	return node;
}

BinaryTreeNode* Search(BinaryTreeNode* node, int value)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->Data == value)
	{
		return node;
	}

	if (node->Data > value)
	{
		return Search(node->Left, value);
	}

	else
	{
		return Search(node->Right, value);
	}
}

int GetCount(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return GetCount(node->Left) + GetCount(node->Right) + 1;
}

BinaryTreeNode* SearchMax(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}

BinaryTreeNode* SearchMin(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Left != nullptr)
	{
		node = node->Left;
	}

	return node;
}
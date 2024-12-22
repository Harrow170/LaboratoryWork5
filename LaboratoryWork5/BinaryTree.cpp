#include "BinaryTree.h"
#include "BinaryTreeNode.h"

BinaryTree* CreateTree()
{
	BinaryTree* tree = new BinaryTree();
	tree->Root = nullptr;
	return tree;
}

void Add(BinaryTree* tree, int value)
{
	if (tree->Root == nullptr)
	{
		tree->Root = CreateNode(value);
		return;
	}

	BinaryTreeNode* current = tree->Root;
	BinaryTreeNode* parent = nullptr;
	while (current != nullptr)
	{
		parent = current;
		if (value < current->Data)
		{
			current = current->Left;
		}

		else
		{
			current = current->Right;
		}
	}

	if (value < parent->Data)
	{
		parent->Left = CreateNode(value);
	}

	else
	{
		parent->Right = CreateNode(value);
	}
}

BinaryTree* Remove(BinaryTree* tree, int value)
{
	if (tree->Root == nullptr)
	{
		return nullptr;
	}

	tree->Root = RemoveWrapper(tree->Root, value);
	if (tree->Root == nullptr)
	{
		//delete tree;
		return nullptr;
	}

	return tree;
}

BinaryTreeNode* RemoveWrapper(BinaryTreeNode* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (value < node->Data)
	{
		node->Left = RemoveWrapper(node->Left, value);
	}

	else if (value > node->Data)
	{
		node->Right = RemoveWrapper(node->Right, value);
	}

	else
	{
		if (node->Left == nullptr)
		{
			BinaryTreeNode* temp = node->Right;
			delete node;
			return temp;
		}

		else if (node->Right == nullptr)
		{
			BinaryTreeNode* temp = node->Left;
			delete node;
			return temp;
		}

		BinaryTreeNode* temp = SearchMinWrapper(node->Right);
		node->Data = temp->Data;
		node->Right = RemoveWrapper(node->Right, temp->Data);
		
	}

	return node;
}

BinaryTreeNode* Search(BinaryTree* tree, int value)
{
	if (tree == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* current = tree->Root;
	while (current != nullptr)
	{
		if (current->Data == value)
		{
			return current;
		}

		else if (value < current->Data)
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

int GetCount(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return GetCount(node->Left) + GetCount(node->Right) + 1;
}

BinaryTree* SearchMax(BinaryTree* tree)
{
	if (tree == nullptr || tree->Root == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* current = tree->Root;
	while (current->Right != nullptr)
	{
		current = current->Right;
	}

	BinaryTree* max = CreateTree();
	max->Root = current;
	return max;
}

BinaryTree* SearchMin(BinaryTree* tree)
{
	if (tree->Root == nullptr || tree == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* current = tree->Root;
	while (current->Left != nullptr)
	{
		current = current->Left;
	}

	BinaryTree* min = CreateTree();
	min->Root = current;
	return min;
}

BinaryTreeNode* SearchMinWrapper(BinaryTreeNode* node)
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

void Free(BinaryTreeNode* node)
{
	if (node != nullptr)
	{
		Free(node->Left);
		Free(node->Right);
		delete node;
		node = nullptr;
	}
}

void FreeTree(BinaryTree* tree)
{
	if (tree == nullptr)
	{
		return;
	}

	Free(tree->Root);
	delete tree;
}
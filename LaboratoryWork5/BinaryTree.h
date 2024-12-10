#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root;

	BinaryTree() : Root(nullptr) {}
};

BinaryTree* CreateTree();

void Add(BinaryTreeNode*& node, int value);

BinaryTreeNode* Remove(BinaryTreeNode*& node);

int GetCount(BinaryTreeNode* node);

BinaryTreeNode* Search(BinaryTreeNode* node, int value);

BinaryTreeNode* SearchMax(BinaryTreeNode* node);

BinaryTreeNode* SearchMin(BinaryTreeNode* node);

void Free(BinaryTreeNode* node);
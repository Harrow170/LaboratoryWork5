#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root;

	BinaryTree() : Root(nullptr) {}
};

BinaryTree* CreateTree();
//void InitializeTree(BinaryTree* tree);

BinaryTreeNode* Add(BinaryTreeNode* node, int value);
//void Add(BinaryTreeNode*& node, int value);

BinaryTreeNode* Remove(BinaryTreeNode*& node, int value);
//void Remove(BinaryTreeNode*& node, int value);

int GetCount(BinaryTreeNode* node);

BinaryTreeNode* Search(BinaryTreeNode* node, int value);

BinaryTreeNode* SearchMax(BinaryTreeNode* node);

BinaryTreeNode* SearchMin(BinaryTreeNode* node);

void Free(BinaryTreeNode* node);
#pragma once
#include "BinaryTreeNode.h"

struct BinaryTree
{
	BinaryTreeNode* Root;
};

BinaryTree* CreateTree();
//void InitializeTree(BinaryTree* tree);

//BinaryTreeNode* Add(BinaryTreeNode* node, int value);
void Add(BinaryTree* tree, int value);

BinaryTree* Remove(BinaryTree* tree, int value);
//void Remove(BinaryTreeNode*& node, int value);

BinaryTreeNode* RemoveWrapper(BinaryTreeNode* node, int value);

int GetCount(BinaryTreeNode* node);

BinaryTreeNode* Search(BinaryTree* tree, int value);

BinaryTree* SearchMax(BinaryTree* tree);

BinaryTree* SearchMin(BinaryTree* tree);

BinaryTreeNode* SearchMinWrapper(BinaryTreeNode* node);

void Free(BinaryTreeNode* node);

void FreeTree(BinaryTree* tree);
#include "BinaryTreeNode.h"

BinaryTreeNode* CreateNode(int data)
{
	BinaryTreeNode* node = new BinaryTreeNode();
	node->Data = data;
	node->Left = nullptr;
	node->Right = nullptr;
	return node;
}
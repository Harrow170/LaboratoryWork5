#include "BinaryTreeNode.h"

BinaryTreeNode* CreateNode(int data, BinaryTreeNode* parent = nullptr)
{
	return new BinaryTreeNode(data, parent);
}
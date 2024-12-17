#pragma once

struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode* Parent;
};

BinaryTreeNode* CreateNode(int data);
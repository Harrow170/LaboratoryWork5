#pragma once

struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode* Parent;

	BinaryTreeNode(int data)
		:Data(data), Left(nullptr), Right(nullptr), Parent(nullptr){}
};

BinaryTreeNode* CreateNode(int data);
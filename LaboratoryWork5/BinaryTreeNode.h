#pragma once

struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode* Parent;

	BinaryTreeNode(int data, BinaryTreeNode* parent = nullptr)
		:Data(data), Left(nullptr), Right(nullptr), Parent(parent){}
};

BinaryTreeNode CreateNode(int data, BinaryTreeNode* parent = nullptr);
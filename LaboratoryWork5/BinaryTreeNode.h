#pragma once

//! \brief struct of tree node
struct BinaryTreeNode
{
	//! \brief data of node
	int Data;

	//! \brief left pointer
	BinaryTreeNode* Left;

	//! \brief right pointer
	BinaryTreeNode* Right;
	//BinaryTreeNode* Parent;
};

//! \brief create node
//! \param data 
//! \return node
BinaryTreeNode* CreateNode(int data);
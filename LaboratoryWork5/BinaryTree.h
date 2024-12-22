#pragma once
#include "BinaryTreeNode.h"

//! \brief struct of tree
struct BinaryTree
{
	//! \brief pointer to the root of the tree
	BinaryTreeNode* Root;
};

//! \brief create tree
//! \return tree
BinaryTree* CreateTree();
//void InitializeTree(BinaryTree* tree);

//BinaryTreeNode* Add(BinaryTreeNode* node, int value);
//! \brief add to tree
//! \param pointer on tree
//! \param value of element
void Add(BinaryTree* tree, int value);

//! \brief remove from tree
//! \param pointer on tree
//! \param value of element
BinaryTree* Remove(BinaryTree* tree, int value);
//void Remove(BinaryTreeNode*& node, int value);

//! \brief remove wrapper
//! \param pointer on tree node
//! \param value of element
BinaryTreeNode* RemoveWrapper(BinaryTreeNode* node, int value);

//! \brief count of nodes
//! \param pointer on tree node
int GetCount(BinaryTreeNode* node);

//! \brief search in tree
//! \param pointer on tree
//! \param value of element
BinaryTreeNode* Search(BinaryTree* tree, int value);

//! \brief search max in tree
//! \param pointer on tree
BinaryTree* SearchMax(BinaryTree* tree);

//! \brief search min in tree
//! \param pointer on tree
BinaryTree* SearchMin(BinaryTree* tree);

//! \brief search min wrapper
//! \param pointer on tree node
BinaryTreeNode* SearchMinWrapper(BinaryTreeNode* node);

//! \brief free tree node
//! \param pointer on tree node
void Free(BinaryTreeNode* node);

//! \brief free tree
//! \param pointer on tree
void FreeTree(BinaryTree* tree);
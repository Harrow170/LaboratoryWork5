#pragma once
#include "TreapNode.h"

//! \brief struct of treap
struct Treap
{
	//! \brief pointer to treap root
	TreapNode* Root;

	//Treap() : Root(nullptr) {}
};

//! \brief create treap
//! \return treap
Treap* CreateTreap();

//! \brief find element
//! \param pointer to treap
//! \param value of element
TreapNode* Find(Treap* treap, int value);

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

TreapNode* Merge(TreapNode* left, TreapNode* right);

void InsertUnoptimized(Treap* treap, int key);

void InsertOptimized(Treap* treap, int key);

void DeleteUnoptimized(Treap* treap, int key);

void DeleteOptimized(Treap* treap, int key);

void FreeTreap(TreapNode* node);

void FreeTreapWrapper(Treap*& treap);
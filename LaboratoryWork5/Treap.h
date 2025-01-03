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

//! \brief split treap
//! \param pointer to treap node
//! \param key of element
//! \param pointer to left
//! \param pointer to right
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

//! \brief merge treap
//! \param pointer left
//! \param pointer right
TreapNode* Merge(TreapNode* left, TreapNode* right);

//! \brief insert unoptimized
//! \param pointer to treap
//! \param key of element
Treap* InsertUnoptimized(Treap* treap, int key);

//! \brief insert optimized
//! \param pointer to treap
//! \param key of element
Treap* InsertOptimized(Treap* treap, int key);

//! \brief delete unoptimized
//! \param pointer to treap
//! \param key of element
Treap* DeleteUnoptimized(Treap* treap, int key);

//! \brief delete optimized
//! \param pointer to treap
//! \param key of element
Treap* DeleteOptimized(Treap* treap, int key);

//! \brief free treap node
//! \param pointer to treap node
void FreeTreap(TreapNode* node);

//! \brief free wrapper
//! \param pointer ro treap
void FreeTreapWrapper(Treap*& treap);
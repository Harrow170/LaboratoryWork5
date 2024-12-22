#pragma once
#include "TreapNode.h"

struct Treap
{
	TreapNode* Root;

	Treap() : Root(nullptr) {}
};

Treap* CreateTreap();

TreapNode* Find(Treap* treap, int value);

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

TreapNode* Merge(TreapNode* left, TreapNode* right);

Treap* InsertUnoptimized(Treap* treap, int key);

Treap* InsertOptimized(Treap* treap, int key);

Treap* DeleteUnoptimized(Treap* treap, int key);

Treap* DeleteOptimized(Treap* treap, int key);

void FreeTreap(TreapNode* node);

void FreeTreapWrapper(Treap*& treap);
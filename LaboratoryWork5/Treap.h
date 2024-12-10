#pragma once
#include "TreapNode.h"

struct Treap
{
	TreapNode* Root;

	Treap() : Root(nullptr) {}
};

Treap* CreateTreap();

TreapNode* Find(TreapNode* node, int value);

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

TreapNode* Merge(TreapNode* left, TreapNode* right);

void InsertUnoptimized(Treap*& treap, int key);

void InsertOptimized(Treap*& treap, int key);

void DeleteUnoptimized(Treap*& treap, int key);

void DeleteOptimized(Treap*& treap, int key);

void FreeTreap(TreapNode* node);

void FreeTreapWrapper(Treap*& treap);
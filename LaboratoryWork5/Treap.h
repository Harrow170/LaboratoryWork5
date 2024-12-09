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

void Insert1Way(Treap* treap, int key);

void Insert2Way(Treap* treap, int key);

void Delete1Way(Treap* treap, int key);

void Delete2Way(Treap* treap, int key);

void FreeTreap();
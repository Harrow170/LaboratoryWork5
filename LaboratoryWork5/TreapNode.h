#pragma once
#include <cstdlib>

struct TreapNode
{
	int Key;
	int Priority;
	TreapNode* Left;
	TreapNode* Right;

	TreapNode(int key) : Key(key), Priority(rand()), Left(nullptr), Right(nullptr) {}
};

TreapNode* CreateTreapNode(int key);
#pragma once
#include <cstdlib>

struct TreapNode
{
	int Key;
	int Priority;
	int Value;
	TreapNode* Left;
	TreapNode* Right;

	TreapNode(int key) : Key(key), Priority(rand()), Value(rand()), Left(nullptr), Right(nullptr) {}
};

TreapNode* CreateTreapNode(int key);
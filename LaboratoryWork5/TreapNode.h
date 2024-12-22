#pragma once
#include <cstdlib>

//! \brief node struct
struct TreapNode
{
	//! \brief key of element
	int Key;

	//! \brief priority of element
	int Priority;
	//int Value;

	//! \brief pointer left
	TreapNode* Left;

	//! \brief pointer right
	TreapNode* Right;

	//TreapNode(int key) : Key(key), Priority(rand()), Value(rand()), Left(nullptr), Right(nullptr) {}
};

//! \brief create treap node
//! \param key
//! \return node
TreapNode* CreateTreapNode(int key);
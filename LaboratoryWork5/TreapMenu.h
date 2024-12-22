#pragma once
#include "Treap.h"
#include "TreapNode.h"

//! \brief display treap
//! \param pointer to treap node
//! \param space between
void DisplayTreap(TreapNode* node, int indent);

//! \brief menu
//! \param pointer to treap
void TreapMenu(Treap* treap);
#pragma once
#include "binary-node.h"

template<typename T, typename VST>
void traversePreOrderRecurse(BinaryNodePos(T) pos, VST& visit)
{
	if (!pos)
		return;
	visit(pos->data_);
	traversePreOrderRecurse(pos->left_);
	traversePreOrderRecurse(pos->right_);
}

template<typename T, typename VST>
void traverseInOrderRecurse(BinaryNodePos(T) pos, VST& visit)
{
	if (!pos)
		return;
	traverseInOrderRecurse(pos->left_);
	visit(pos->data_);
	traverseInOrderRecurse(pos->right_);
}

template<typename T, typename VST>
void traversePostOrderRecurse(BinaryNodePos(T) pos, VST& visit)
{
	if (!pos)
		return;
	traversePostOrderRecurse(pos->left_);
	traversePostOrderRecurse(pos->right_);
	visit(pos->data_);
}


#pragma once


#include "../BinarySearchTree/bst.h"

template <typename T>
class SPlay : public BST<T>
{
protected:
	BinaryNodePos(T) splay(BinaryNodePos(T) v);

public:
	BinaryNodePos(T)& search(const T& e);
	BinaryNodePos(T) insert(const T& e);
	bool remove(const T& e);
};









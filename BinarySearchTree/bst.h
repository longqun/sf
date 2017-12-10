#pragma once


#include "../binarytree/binary-tree.h"

template <typename T> class BST : public BinaryTree<T>
{
protected:
	BinaryNodePos(T) hot_;

	//BinaryNodePos(T) rotateAt( BinaryNodePos(T) x);
public:
	virtual BinaryNodePos(T) & search(const T & e);
	virtual BinaryNodePos(T) insert( const T &e);
	//virtual bool remove( const T &e);


};

#include "bst-implementation.h"
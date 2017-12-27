
#pragma once
#include "binary-tree.h"
#include "stdlib.h"





template<typename T>
inline int BinaryTree<T>::updateHeight(BinaryNodePos(T) pos)
{
	return pos->height_ = __max(stature(pos->left_),stature(pos->right_)) + 1;
}

template<typename T>
inline void BinaryTree<T>::updateHeightAbove(BinaryNodePos(T) pos)
{
	/*
	if (pos != NULL)
	updateHeight(pos);
	updateHeightAbove(pos->parent_);
	*/

	while (pos)
	{
		updateHeight(pos);;
		pos = pos->parent_;
	}

}



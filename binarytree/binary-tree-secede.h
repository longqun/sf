#pragma once



template<typename T>
inline BinaryTree<T>* BinaryTree<T>::secode(BinaryNodePos(T) pos)
{
	if (pos == NULL)
		return NULL;
	FromParentTo(pos) = NULL;
	updateHeightAbove(pos->parent_);
	BinaryTree<T>* retTree = new BinaryTree<T>();
	retTree->root_ = pos;
	retTree->size_ = pos->size_;
	size_ -= retTree->size_;
	return retTree;
}
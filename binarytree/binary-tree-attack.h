#pragma once


template<typename T>
inline BinaryNodePos(T) BinaryTree<T>::attachAsLeft(BinaryNodePos(T) pos, BinaryTree<T>*& t)
{
	if (pos->left_ = t->root_)
		t->root_->parent_ = pos;
	size_ += t->size_;
	updateHeightAbove(pos);
	t->root_ = NULL;
	t->size_ = NULL;
	delete t;
	t = NULL;
	return pos;
}

template<typename T>
inline BinaryNodePos(T) BinaryTree<T>::attachAsRight(BinaryNodePos(T) pos, BinaryTree<T>*& t)
{
	if (pos->right_ = t->root_)
		t->root_->parent_ = pos;
	size_ += t->size_;
	updateHeightAbove(pos);
	t->root_ = NULL;
	t->size_ = NULL;
	delete t;
	t = NULL;
	return pos;
}
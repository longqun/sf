#pragma once


template<typename T>
inline int BinaryTree<T>::updateHeight(BinaryNodePos(T) pos)
{
	return pos->height_ = max(pos->left_ == NULL ? 0 : pos->left_->height_, pos->right_ == NULL ? 0 : pos->right_->height_) + 1;
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
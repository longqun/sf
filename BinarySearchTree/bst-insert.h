#pragma once


template<typename T>
BinaryNodePos(T) BST<T>::insert(const T & e)
{
	BinaryNodePos(T) target = search(e);
	if (target)
		return target;
	target = new BinaryNode<T>(e, hot_);
	if (hot_)
	{
		if (IsLeftChild(target))
			hot_->left_ = hot_;
		else
			hot_->right_ = hot_;
	}
	size_++;
	updateHeightAbove(target);
	return target;
}
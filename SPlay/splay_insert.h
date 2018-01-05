#pragma once


template<typename T>
inline BinaryNodePos(T) SPlay<T>::insert(const T & e)
{
	if (!root_)
	{
		size_++;
		return root_ = new BinaryNodePos(e);
	}
	if (e == search(e)->data_)
		return root_;
	BinaryNodePos(T) t = root_;
	if (e > t->data_)
	{
		t->parent_ = root_ = new BinaryNodePos(e, NULL, t, t->right_);
		if (HasRightChild(t))
			t->right_->parent_ = root_;
	}
	else
	{
		t->parent_ = root_ = new BinaryNodePos(e, NULL, t->left_, t);
		if (HasLeftChild(t))
			t->left_->parent_ = root_;
	}
	updateHeightAbove(t);
	return root_;
}
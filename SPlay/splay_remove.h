#pragma once

template<typename T>
inline bool SPlay<T>::remove(const T & e)
{
	BinaryNodePos(T) v = search(e);

	if (!v || v->data_ != e)
		return false;
	if (!HasLeftChild(v))
	{
		root_ = v->right_;
		if (root_)
			root_->parent_ = NULL;
	}
	else if (!HasRightChild(v))
	{
		root_ = v->left_;
		if (root_)
			root_->parent = NULL;
	}
	else
	{
		root_ = v->right_;
		root_->parent_ = NULL;
		BinaryNodePos(T) m = search(e);
		m->left_ = v->left_;
		m->right_ = v->right_;

		v->left_->parent_ = m;
		v->right_->parent_ = m;

		root_ = m;

		root_->parent_ = NULL;
	}
	if (root_)
		updateHeight(root_);
	size_--;
	delete v;
	return true;
}

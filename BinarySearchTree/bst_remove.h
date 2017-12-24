#pragma once


template<typename T>
static BinaryNodePos(T) removeAt(BinaryNodePos(T) &x, BinaryNodePos(T) &hot)
{
	BinaryNodePos(T) del = x;
	BinaryNodePos(T) succ = NULL;
	if (!HasLeftChild(del))
	{
		succ = x = x->right_;
	}
	else if (!HasRightChild(del))
	{
		succ = x = x->left_;
	}
	else
	{
		del = del->succ();
		swap(del->data_, x->data_);

		BinaryNodePos(T) parent = del->parent_;
		//if parent node has only two child no grandson
		((parent == x) ? parent->right_ : parent->left_) = succ = del->right_;
	}
	hot = del->parent_;
	if (succ)
		succ->parent_ = hot;
	delete del;
	return succ;
}

template<typename T>
inline bool BST<T>::remove(const T & e)
{
	BinaryNodePos(T) &del = search(e);
	if (!del)
		return false;
	removeAt(del, hot_);
	updateHeightAbove(hot_);
	return true;
}
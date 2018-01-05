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



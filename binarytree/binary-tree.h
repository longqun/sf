#pragma once
#include "binary-node.h"
#include "../stack/stack.h"

template<typename T>
class BinaryTree
{
protected:
	int size_;
	BinaryNodePos(T) root_;
	//update pos height
	virtual int updateHeight(BinaryNodePos(T) pos);
	void updateHeightAbove(BinaryNodePos(T) pos);

public:
	BinaryTree() :size_ = 0, root_ = NULL
	{}

		~BinaryTree()
	{
		if (size_ > 0)
			remove(root_);
	}

	int size() { return size_; }

	bool empty() { return !size_; }

	BinaryNodePos(T) root() { return root_; }

	BinaryNodePos(T) insertAsRoot(const T&val);

	BinaryNodePos(T) insertAsLeft(BinaryNodePos(T)pos, const T&val);

	BinaryNodePos(T) insertAsRight(BinaryNodePos(T)pos, const T&val);

	BinaryNodePos(T) attachAsLeft(BinaryNodePos(T)pos, BinaryTree<T>*&t);

	BinaryNodePos(T) attachAsRight(BinaryNodePos(T)pos, BinaryTree<T>*&t);

	//remove pos from the tree and return a tree
	BinaryTree<T>* secode(BinaryNodePos(T) pos);

	template<typename VST>
	void travelLevelOrder(VST&visit)
	{
		if (root_)
			root_->travelLevel(visit);
	}

	template<typename VST>
	void travePreOrder(VST&visit)
	{
		if (root_)
			root_->travelPreOder(visit);
	}

	template<typename VST>
	void traveInOrder(VST&visit)
	{
		if (root_)
			root_->travelInOrder(visit);
	}

	template<typename VST>
	void travePostOrder(VST&visit)
	{
		if (root_)
			root_->travelPostOrder(visit);
	}


	int remove(BinaryNodePos(T) pos);

};

template<typename T>
inline int BinaryTree<T>::remove(BinaryNodePos(T) pos)
{
	/*
	if (pos == NULL)
		return 0;
	int left = remove(pos->left_);
	int right = remove(pos->right_);
	delete pos;
	return left + right + 1;
	*/

	int ret = 0;
	if (pos != NULL)
		s.push(pos);
	while (!s.empty())
	{
		pos = s.pop();
		if (pos->left_)
			s.push(pos->left_);
		if (pos->right_)
			s.push(pos->right_);
		delete pos;
	}
	return ret;
}




template<typename T>
inline BinaryNodePos(T) BinaryTree<T>::attachAsLeft(BinaryNodePos(T) pos, BinaryTree<T>*& t)
{
	if (pos->left_ = t->root_)
		t->root_->parent_ = pos;
	size_ += t->size_;
	t->root_ = NULL;
	t->size_ = NULL;
	release(t);
	t = NULL;
	return pos;
}

template<typename T>
inline BinaryNodePos(T) BinaryTree<T>::attachAsRight(BinaryNodePos(T) pos, BinaryTree<T>*& t)
{
	return BinaryNodePos(T)();
}
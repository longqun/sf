#pragma once
#include "binary-node.h"
#include "../stack/stack.h"
#include "binary-define.h"

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

	// remove ths pos and child
	int remove(BinaryNodePos(T) pos);

};





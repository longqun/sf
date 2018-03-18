#pragma once

#include "../vector/vector.h"

#define BTNodePosi(T) BTNode<T>*

template <typename T>struct BTNode
{
	BTNodePosi(T) parent_;
	Vector<T> key_;
	Vector<BTNodePosi(T)> child_;
	BTNode() 
	{
		parent_ = NULL;
		child_.insert(0,nullptr);
	}

	BTNode(T e, BTNodePosi(T) lc = nullptr, BTNodePosi(T) rc = nullptr)
	{
		parent = nullptr;
		key_.insert(0,e);
		child_.insert(0,lc);
		child_.insert(1,rc);
		if (lc)
			lc->parent_ = this;
		if (rc)
			rc->parent_ = this;
	}
};
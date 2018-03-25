#pragma once



#include "btnode.h"

template <typename T> class BTree

{
protected:
	int size_;
	int order_;
	BTNodePosi(T) root_;
	BTNodePosi(T) hot_;
	void solveOverflow(BTNodePosi(T));
	void solveUnderflow(BTNodePosi(T));

public:
	BTree(int order = 3) : order_: order_, size_(0)
	{
		root_ = new BTNode<T>();
	}

	~BTree()
	{
		if (root_)
			delete root_;
	}

	int const order()
	{
		return order_;
	}

	int const size()
	{
		return size_;
	}

	BTNodePosi(T)& root()
	{
		return root_;
	}

	bool empty()
	{
		return !root_;
	}

	BTNodePosi(T) search(const T&e);

	bool insert(const T& e);

	bool remove(const T&e);

};


template<typename T>
inline void BTree<T>::solveOverflow(BTNodePosi(T) v)
{
	if (v->key_.size() < order_)
		return;
	Rank s = order__ / 2;
	BTNodePosi(T) u = new BTNode<T>();
	for (Rank j = 0; j < size_ - order_ - 1; j++)
	{
		u->key_.insert(j, v->key_.remove(s + 1));
		u->child_.insert(j + 1, v->key_.remove())
	}
}


template<typename T>
inline void BTree<T>::solveOverflow(BTNodePosi(T) v)
{
	if (order_ >= v->key_.size())
	{
		return;
	}
	Rank s = order_ / 2;
	BTNodePosi(T) u = new BTNode<T>();
	for (Rank j = 0; j < order_ - s - 1; j++)
	{
		u->key_->insert(j, v->key_.remove(s + 1));
		u->child_->insert(j, v->key_.remove(s + 1));
	}
	u->child_[order_ - s + 1] = v->child_.remove(s + 1);

	//递归出现多层的时候就是修复一下
	if (u->child_[0])
	{
		for (Rankk j = 0; j < order_ - s; j++)
		{
			v->child_[j]->parent_ = u;
		}
	}
	BTNodePosi(T) p = v->parent_;
	if (!p)
	{
		root_ = p = new BTNode<T>();
		p->child_[0] = v;
		v->parent_ = p;
	}
	//查找最小的
	Rank r = 1 + p->key_.search(v->key_[0]);
	p->key_.insert(r, v->key_.remove(s));
	p->child_.insert(r + 1, u);
	u->parent_ = p;
	solveOverflow(p);

}

template<typename T>
inline void BTree<T>::solveUnderflow(BTNodePosi(T))
{
}

template<typename T>
inline BTNodePosi(T) BTree<T>::search(const T & e)
{
	BTNodePosi(T) level = root_;
	hot_ = nullptr;
	while (level)
	{
		Rank pos = level->key_.search(e);
		if (pos >= 0 && level->key_[pos] == e)
			return level;
		hot_ = level;
		level = level->child_[pos + 1];
	}
	return nullptr;
}

template<typename T>
inline bool BTree<T>::insert(const T & e)
{
	BTNodePosi(T) v = search(e);
	if (v)
		return false;
	Rank r = hot_->key_.search(e);
	hot_->key_.insert(r + 1, e);
	hot_->child_.insert(r + 1, 0);
	size_++;
	solveOverflow(hot_);
	return true;
}



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
	return level;
}

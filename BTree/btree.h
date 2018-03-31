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
	BTree(int order = 3) : order_(order), size_(0)
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

	void printBtree();

	void printBtreeRecurse(BTNodePosi(T));

};





template<typename T>
inline void BTree<T>::solveOverflow(BTNodePosi(T) v)
{
	if (order_ >= v->child_.size())
	{
		return;
	}
	Rank s = order_ / 2;
	BTNodePosi(T) u = new BTNode<T>();
	for (Rank j = 0; j < order_ - s - 1; j++)
	{
		u->child_.insert(j, v->child_.remove(s + 1));
		u->key_.insert(j, v->key_.remove(s + 1));
		

	}
	u->child_[order_ - s - 1] = v->child_.remove(s + 1);

	//递归出现多层的时候就是修复一下
	if (u->child_[0])
	{
		for (Rank j = 0; j < order_ - s; j++)
		{
			u->child_[j]->parent_ = u;
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
inline void BTree<T>::solveUnderflow(BTNodePosi(T)v)
{
	if ((order_ + 1) / 2 <= v->child_.size())
		return;
	BTNodePosi(T) p = v->parent_;
	if (!p)
	{
		if (!v->key_.size() && v->child_[0])
		{
			root_ = v->child_[0];
			root_->parent_ = nullptr;
			v->child_[0] = nullptr;
			delete v;
			return;
		}
	}
	Rank r = 0;
	while (p->child_[r] != v)
		r++;
	if (0 < r)
	{
		BTNodePosi(T) ls = p->child_[r - 1];
		if ((order_ + 1) / 2 < ls->child_.size())
		{
			v->key_.insert(0, p->key_[r - 1]);
			p->key_[r - 1] = ls->key_.remove(ls->key_.size() - 1);
			v->child_.insert(0, ls->child_.remove(ls->child_.size() - 1));
			if (v->child_[0])
				v->child_[0]->parent_ = v;
			return;
		}
	}

	if (p->child_.size() - 1 > r)
	{
		BTNodePosi(T) rs = p->child_[r + 1];
		if ((order_ + 1) / 2 < rs->child_.size())
		{
			v->key_.insert(v->key_.size(), p->key_[r]);
			p->key_[r] = rs->key_.remove(0);
			v->child_.insert(v->child_.size(), rs->child_.remove(0));

			if (v->child_[v->child_.size() - 1])
				v->child_[v->child_.size() - 1]->parent_ = v;
			return;
		}
	}

	if (0 < r)
	{
		BTNodePosi(T) ls = p->child_[r - 1];
		ls->key_.insert(ls->key_.size(), p->key_.remove(r - 1));
		p->child_.remove(r);
		ls->child_.insert(ls->child_.size(), v->child_.remove(0));
		if (ls->child_[ls->child_.size() - 1])
			ls->child_[ls->child_.size() - 1]->parent_ = ls;
		while (!v->key_.empty())
		{
			ls->key_.insert(ls->key_.size(), v->key_.remove(0));
			ls->child_.insert(ls->child_.size(), v->child_.remove(0));
			if (ls->child_[ls->child_.size() - 1])
				ls->child_[ls->child_.size() - 1]->parent_ = ls;
		}
		delete v;
	}
	else
	{
		BTNodePosi(T) rs = p->child_[r + 1];
		rs->key_.insert(0, p->key_.remove(r));
		p->child_.remove(r);
		rs->child_.insert(0, v->child_.remove(v->child_.size() - 1));
		if (rs->child_[0])
			rs->child_[0]->parent_ = rs;
		while (!v->key_.empty())
		{
			rs->key_.insert(0, v->key_.remove(v->key_.size() - 1));
			rs->child_.insert(0, v->child_.remove(v->child_.size() - 1));
			if (rs->child_[0])
				rs->child_[0]->parent_ = rs;
		}
		delete v;
	}
	solveUnderflow(p);
	return;
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
	hot_->child_.insert(r + 2, NULL);
	size_++;
	solveOverflow(hot_);
	return true;
}




template<typename T>
inline bool BTree<T>::remove(const T & e)
{
	BTNodePosi(T) v = search(e);
	if (!v)
		return false;
	Rank r = v->key_.search(e);
	if (v->child_[0])
	{
		BTNodePosi(T) u = v->child_[r + 1];
		while (u->child_[0])
			u = u->child_[0];
		v->key_[r] = u->key_[0];
		v = u;
		r = 0;
	}
	v->key_.remove(r);
	v->child_.remove(r + 1);
	size_--;
	solveUnderflow(v);

	return true;
}

template<typename T>
inline void BTree<T>::printBtree()
{
	
	printBtreeRecurse(root_);
}



template<typename T>
inline void BTree<T>::printBtreeRecurse(BTNodePosi(T) node)
{
	if (node == NULL)
		return;
	if (node->parent_)
	{
		if (node->parent_->key_.size()) {
			printf("%s ", "parent first is");
			for (int i = 0; i < node->parent_->key_.size(); i++)
			{
				printf(" %d ", node->parent_->key_[i]);;
			}
			printf("%s","\n");
		}
			
	}
	for (int i = 0; i < node->key_.size(); i++)
	{
		printf("%d ", node->key_[i]);
	}
	printf("\n");
	for (int i = 0; i < node->child_.size(); i++)
	{
		printBtreeRecurse(node->child_[i]);
	}
}



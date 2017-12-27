#pragma once

#include "../BinarySearchTree/bst.h"

#define Balanced(x) (stature((x)->left_) == (stature((x)->right_)))
#define BalFac(x) (stature((x)->left_) - (stature((x)->right_)))
#define AvlBalanced(x ) ((-2 < BalFac(x)) && (BalFac(x) < 2))

#define tallerChild(x) (	\
	stature( (x)->left_ )  > stature( (x)->right_ ) ? (x)->left_ : (	\
	stature( (x)->left_ )  < stature( (x)->right_ ) ? (x)->right_ : (	\
	IsLeftChild( (x) ) ? (x)->left_ ; (x)->right_	\
	)\
	)\
)



template <typename T> class AVL : public BST<T>
{

public:
	BinaryNodePos(T) insert(const T&e);
	bool remove(const T&e);
	BinaryNodePos(T) rotateAt(BinaryNodePos(T) v);
	BinaryNodePos(T) connect34(BinaryNodePos(T) a, BinaryNodePos(T) b, BinaryNodePos(T) c,
		BinaryNodePos(T) t0, BinaryNodePos(T) t1, BinaryNodePos(T) t2, BinaryNodePos(T) t3);
	BinaryNodePos(T) & tc(BinaryNodePos(T) &x);
};

template <typename T>
BinaryNodePos(T) & AVL<T>::tc(BinaryNodePos(T) &x)
{
	if (stature((x)->left_) > stature((x)->right_))
	{
		return x->left_;
	}
	else
	{
		if (stature((x)->left_) < stature((x)->right_))
			return x->right_;
		else
		{
			if (IsLeftChild((x)))
				return x->left_;
			else
				return x->right_;
		}
	}
}

//amazing idea
template<typename T>
inline BinaryNodePos(T) AVL<T>::connect34(BinaryNodePos(T) a, BinaryNodePos(T) b, BinaryNodePos(T) c, BinaryNodePos(T) t0, BinaryNodePos(T) t1, BinaryNodePos(T) t2, BinaryNodePos(T) t3)
{
	a->left_ = t0;
	if (t0)
		t0->parent_ = a;
	a->right_ = t1;
	if (t1)
		t1->parent_ = b;
	updateHeight(a);

	c->left_ = t2;
	if (t2)
		t2->parent_ = c;
	c->right_ = t3;
	if (t3)
		t3->parent_ = c;
	updateHeight(c);
	b->left_ = a;
	b->right_ = c;
	a->parent_ = b;
	c->parent_ = b;
	updateHeight(b);

	return b;
}

template<typename T>
inline BinaryNodePos(T) AVL<T>::rotateAt(BinaryNodePos(T) v)
{
	BinaryNodePos(T) p = v->parent_;
	BinaryNodePos(T) g = p->parent_;
	if (IsLeftChild(v))
	{
		if (IsLeftChild(p))
		{
			p->parent_ = g->parent_;
			return connect34(v, p, g, v->left_, v->right_, p->right_, g->right_);
		}
		else
		{
			v->parent_ = g->parent_;
			return connect34(g, v, p, g->left_, v->left_, v->right_, p->right_);
		}
	}
	else
	{
		if (IsRightChild(p))
		{
			p->parent_ = g->parent_;
			return connect34(g, p, v, g->left_, p->left_, v->left_, v->right_);
		}
		else
		{
			v->parent_ = g->parent_;
			return connect34(p, v, g, p->left_, v->left_, v->right_, g->right_);
		}

	}

}

template<typename T>
inline bool AVL<T>::remove(const T & e)
{
	BinaryNodePos(T) &x = search(e);
	if (!x)
		return false;
	removeAt(x, hot_);
	for (BinaryNodePos(T) g = hot_; g != NULL; g = g->parent_)
	{
		if (!AvlBalanced(g))
		{

			g = FromParentTo(g) = rotateAt(tc(tc(g)));
			break;
		}
		else
			updateHeight(g);
	}
	return true;
}

template<typename T>
inline BinaryNodePos(T) AVL<T>::insert(const T & e)
{
	BinaryNodePos(T) &x = search(e);
	if (x)
		return x;
	BinaryNodePos(T) xx = x = new BinaryNode<T>(e, hot_, NULL, NULL);
	size_++;
	for (BinaryNodePos(T) g = hot_; g != NULL; g = g->parent_)
	{
		if (!AvlBalanced(g))
		{
			g = FromParentTo(g) = rotateAt(tc(tc(g)));
			break;
		}
		else
			updateHeight(g);
	}
	return xx;
}
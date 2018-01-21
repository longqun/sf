#pragma once


#include "entry.h"

#define QListNodePosi(T) QuadListNode<T>*

template <typename T>
struct QuadListNode
{
	T entry_;
	QListNodePosi(T) pre_;
	QListNodePosi(T) next_;
	QListNodePosi(T) above_;
	QListNodePosi(T) below_;

	QuadListNode(T e = T(),
		QListNodePosi(T) p = NULL,
		QListNodePosi(T) n = NULL,
		QListNodePosi(T) a = NULL,
		QListNodePosi(T) b = NULL)
		:entry_(e), pre_(p), next_(n), above_(a), below_(b)
	{}

	QListNodePosi(T) insertAsSuccAbove(const T& e, QListNodePosi(T) b = NULL);
};

template<typename T>
inline QListNodePosi(T) QuadListNode<T>::insertAsSuccAbove(const T & e, QListNodePosi(T) b)
{
	QListNodePosi(T) x = new QuadListNode<T>(e, this, succ, NULL, b);
	next_->pre_ = x;
	next_ = x;
	if (b)
		b->above_ = x;
	return x;
}

#pragma once
#ifndef  NULL
#define NULL nullptr
#endif // ! NULL


#define BinaryNodePos(T) BinaryNode<T>*
#define stature(p) ((p)?(p)->height_:-1)
typedef enum { RB_RED, RB_BLACK }RBColor;

template <typename T>
struct BinaryNode
{
	T data_;
	BinaryNodePos(T) parent_;
	BinaryNodePos(T) left_;
	BinaryNodePos(T) right_;
	int height_;
	int npl_;
	//black red tree
	RBColor color_;

	BinaryNode() :parent_(NULL), left_(NULL), right_(NULL), height_(0), npl_(1), color_(RB_RED)
	{}

	BinaryNode(T val, BinaryNodePos(T) p = NULL, BinaryNodePos(T) l = NULL, BinaryNodePos(T)r = NULL, int h = 0 , int npl = 1, RBColor c = RB_RED) :data_(val), parent_(p), left_(l), right_(r), height_(h), npl_(npl), color_(c)
	{
	}

	int size();

	BinaryNodePos(T) insertAsLeft(const T& val);
	BinaryNodePos(T) insertAsRight(const T& val);

	BinaryNodePos(T) succ();

	template <typename VST> void travelLevel(VST&);
	template <typename VST> void travelPreOder(VST&);
	template <typename VST> void travelInorder(VST&);
	template <typename VST> void travelPostOrder(VST&);

	bool operator<(const BinaryNode&node) { return data_ < node.data_; }
	bool operator==(const BinaryNode&node) { return data_ == node.data_; }
};



template<typename T>
inline int BinaryNode<T>::size()
{
	int s = 1;
	if (left)
		s += left_->size();
	if (right_)
		s += right_->size();
	return s;
}



#include "binary-node-implementation.h"
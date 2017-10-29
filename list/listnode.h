#pragma once
typedef int Rank;
#define ListNodePos(T) ListNode<T>*

template <typename T> struct ListNode
{
	T data_;
	ListNodePos(T) pre_;
	ListNodePos(T) next_;

	ListNode() {}
	ListNode(T data, ListNodePos(T) pre = NULL, ListNodePos(T) next = NULL)
		: data_(data), pre_(pre), next_(next) {}

	ListNodePos(T) insertAsPre(T const& data);

	ListNodePos(T) insertAsNext(T const& data);

};
#include "listnode_implementation.h"
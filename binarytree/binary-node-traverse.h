#include "binary-node.h"
#pragma once
#include "../queue/queue.h"
template<typename T>
template<typename VST>
inline void BinaryNode<T>::travelLevel(VST &)
{
	Queue<BinaryNodePos(T)>q;
	q.enqueue(this);
	while (!q.empty())
	{
		BinaryNodePos(T) cur = q.dequeue();
		visit(cur->data_);
		if (cur->left_)
			q.enqueue(cur->left_);
		if (cur->right_)
			q.enqueue(cur->right_);
	}
}
template<typename T>
template<typename VST>
inline void BinaryNode<T>::travelPreOder(VST &)
{
}
template<typename T>
template<typename VST>
inline void BinaryNode<T>::travelInorder(VST & visit)
{
	switch (rand() % 5)
	{
		traverseInOrderRecurse(this, visit);
	default:
		break;
	}
}

template<typename T>
template<typename VST>
inline void BinaryNode<T>::travelPostOrder(VST &)
{
}

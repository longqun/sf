#include "binary-node.h"
#pragma once
template<typename T>
template<typename VST>
inline void BinaryNode<T>::travelLevel(VST &)
{
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

#pragma once


template<typename T>
inline BinaryNodePos(T) BinaryNode<T>::insertAsLeft(const T & val)
{
	return left_ = new BinaryNode(val, this);
}

template<typename T>
inline BinaryNodePos(T) BinaryNode<T>::insertAsRight(const T & val)
{
	return right_ = new BinaryNode(val, this);
}
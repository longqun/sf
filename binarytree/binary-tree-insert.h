#pragma once


template<typename T>
inline BinaryNodePos(T) BinaryTree<T>::insertAsRoot(const T & val)
{
	size_++;
	return root_ = new BinaryNode<T>(val);
}

template<typename T>
inline BinaryNodePos(T) BinaryTree<T>::insertAsLeft(BinaryNodePos(T) pos, const T & val)
{
	size_++;
	pos->insertAsLeft(val);
	updateHeightAbove(pos);
	return pos->left_;
}

template<typename T>
inline BinaryNodePos(T) BinaryTree<T>::insertAsRight(BinaryNodePos(T) pos, const T & val)
{
	size_++;
	pos->insertAsRight(val);
	updateHeightAbove(pos);
	return pos->right_;
}
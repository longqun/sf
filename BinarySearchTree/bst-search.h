#pragma once

template<typename T>
static BinaryNodePos(T)& searchIn(BinaryNodePos(T) root, const T & val, BinaryNodePos(T)& hot)
{
	if (!root || val == root->data_)
		return root;
	hot = root;
	return searchIn(root->data_ > val ? root->right_ : root->left_, val, hot);
}

template<typename T>
BinaryNodePos(T)& BST<T>::search(const T & e)
{
	return searchIn(root_, e, hot_ = NULL);
}
#pragma once

template<typename T>
inline BinaryNodePos(T)& SPlay<T>::search(const T & e)
{
	// TODO: �ڴ˴����� return ���
	BinaryNodePos(T) p = searchIn(root_, e, hot_ = NULL);
	root_ = splay(p ? p : hot_);
	return root_;
}
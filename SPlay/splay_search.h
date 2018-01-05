#pragma once

template<typename T>
inline BinaryNodePos(T)& SPlay<T>::search(const T & e)
{
	// TODO: 在此处插入 return 语句
	BinaryNodePos(T) p = searchIn(root_, e, hot_ = NULL);
	root_ = splay(p ? p : hot_);
	return root_;
}
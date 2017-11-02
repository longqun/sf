#pragma once

template<typename T>
inline int Vector<T>::deduplicate()
{
	int oldSize = size_;
	int i = 1;
	while (i < size_)
	{
		(find(elem_[i], 0, i) < 0) ? i++ : remove(i);
	}
	return oldSize - size_;
}
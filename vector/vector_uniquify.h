#pragma once


template<typename T>
inline int Vector<T>::uniquify()
{
	int i = 0, j = 0;
	while (++j < size_)
	{
		if (elem_[i] != elem_[j])
			elem_[++i] = elem_[j];
	}
	size_ = ++i;
	shrink();
	return j - i;
}
#pragma once

template<typename T>
inline ListNodePos(T) List<T>::selectMax(ListNodePos(T) pos, int n)
{
	ListNodePos(T) max = pos;
	for (int i = 0; i < n - 1; i++)
	{
		pos = pos->next_;
		if (max->data_ < pos->data_)
			max = pos;
	}
	return max;
}

template<typename T>
inline ListNodePos(T) List<T>::selectMax()
{
	return selectMax(first(), size_);
}

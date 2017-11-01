#pragma once


template<typename T>
inline T Vector<T>::remove(Rank r)
{
	T ret = elem_[r];
	remove(r, r + 1);
	return ret;
}

template<typename T>
inline int Vector<T>::remove(Rank lo, Rank hi)
{
	if (lo == hi)
		return 0;
	while (hi < size_)
	{
		elem_[lo++] = elem_[hi++];
	}
	size_ -= hi - lo;
	shrink();
	return hi - lo;
}
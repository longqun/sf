#pragma once

//[lo,hi)
template<typename T>
inline void Vector<T>::copyFrom(T const * a, Rank lo, Rank hi)
{
	elem_ = new T[capacity_ = (hi - lo) * 2];
	size_ = 0;
	while (lo < hi)
	{
		elem_[size_++] = a[lo++];
	}
}
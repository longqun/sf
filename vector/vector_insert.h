#pragma once


template<typename T>
inline Rank Vector<T>::insert(Rank r, T const & val)
{
	expand();
	for (Rank i = size_; i > r; i--)
	{
		elem_[i] = elem_[i - 1];
	}
	elem_[r] = val;
	size_++;
	return r;
}

template<typename T>
inline Rank Vector<T>::insert(T  const &val)
{
	return insert(size_, val);;
}
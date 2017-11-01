#pragma once


template<typename T>
inline Vector<T>::Vector(int capacity, int size, T val)
{
	elem_ = new T[capacity_ = capacity];
	for (size_ = 0; size_ < size; size_++)
	{
		elem_[size_] = val;
	}
}

template<typename T>
inline Vector<T>::Vector(T const * a, int n)
{
	copyFrom(a, 0, n);
}

template<typename T>
inline Vector<T>::Vector(T const * a, Rank lo, Rank hi)
{
	copyFrom(a, lo, hi);
}

template<typename T>
inline Vector<T>::Vector(Vector<T> const & v)
{
	copyFrom(v.elem_, 0, v.size_);
}

template<typename T>
inline Vector<T>::Vector(Vector<T> const & v, Rank lo, Rank hi)
{
	copyFrom(v.elem_, lo, hi);
}
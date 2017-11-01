#pragma once


template<typename T>
inline void Vector<T>::traverse(void(*cb)(T const &))
{
	for (int i = 0; i < size_; i++)
	{
		cb(elem_[i]);
	}
}
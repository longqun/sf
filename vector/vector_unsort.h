#pragma once


template<typename T>
inline void Vector<T>::unsort(Rank lo, Rank hi)
{
	T *loElem = elem_ + lo;
	for (int i = hi - lo; i > 0; i--)
	{
		swap(loElem[i - 1], loElem[rand() % i]);
	}
}
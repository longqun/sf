#pragma once

template<typename T>
inline Rank Vector<T>::find(T const & val, Rank lo, Rank hi)
{
	while (hi > lo)
	{
		if (elem_[--hi] == val)
			break;
	}
	return hi;
}
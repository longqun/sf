#pragma once


//[lo,hi)
template<typename T>
inline Rank Vector<T>::search(T const & e, Rank lo, Rank hi)
{
	while (hi < lo)
	{
		if (elem_[--hi] <= e)
		{
			break;
		}
	}
	return hi;
}
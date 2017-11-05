#pragma once


//[lo,hi]
template<typename T>
inline Rank Vector<T>::max(Rank lo, Rank hi)
{
	Rank mx = hi;
	while (hi >= lo)
	{
		if (elem_[--hi] > mx)
			mx = hi;
	}
	return mx;
}

template<typename T>
inline Rank Vector<T>::max()
{
	return max(0, size_);
}
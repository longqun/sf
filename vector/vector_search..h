#pragma once


//find the closest
template<typename T>static Rank binSearch(T *data, T const &val, Rank lo, Rank hi)
{
	while (lo < hi)
	{
		Rank mid = (lo + hi) >> 1;
		if (data[mid] > val)
		{
			hi = mid;
		}
		else 
		{
			lo = mid + 1;
		}
	}
	return  --lo;
}

//[lo,hi) change to bin
template<typename T>
inline Rank Vector<T>::search(T const & e, Rank lo, Rank hi)
{
	return binSearch(elem_, e, lo, hi);
}
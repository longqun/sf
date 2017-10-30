#pragma once

template<typename T>
inline ListNodePos(T) List<T>::find(T const & var, int n, ListNodePos(T) pos)
{
	//assert(n>0);
	while (n-- > 0)
	{
		if (var == pos->data_)
			return pos;
		pos = pos->pre_;
	}
	return n == -1 ? NULL : pos;
}


template<typename T>
inline ListNodePos(T) List<T>::find(T const & var)
{
	return find(var, size_, last());
}
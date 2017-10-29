#pragma once
template<typename T>
inline ListNodePos(T) List<T>::search(T const & var)
{
	return search(var, size_, last());
}
// <= var   trailer->header;  sorted
template<typename T>
inline ListNodePos(T) List<T>::search(T const & var, int n, ListNodePos(T) pos)
{
	for (int i = 0; i < n; i++)
	{
		if (pos->data_ <= var)
			break;
		pos = pos->pre_;
	}
	return pos;
}
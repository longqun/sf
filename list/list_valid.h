#pragma once


template<typename T>
inline bool List<T>::valid(ListNodePos(T) pos)
{
	if (pos != header_&&pos != trailer_)
		return true;
	return false;
}
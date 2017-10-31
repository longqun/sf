#pragma once

template<typename T>
inline void List<T>::insertNext(ListNodePos(T) pos, T const & val)
{
	pos->insertAsNext( val);
}
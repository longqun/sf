#pragma once

template<typename T>
inline void List<T>::insertPre(ListNodePos(T) pos, T const & val)
{
	pos->insertAsPre(val);
}
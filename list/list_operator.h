#pragma once


template<typename T>
T & List<T>::operator[](Rank n)
{
	//assert(n >= 0 && n < size_);
	ListNodePos(T)* curPos = header_;
	while (n-- > 0)
	{
		curPos = curPos->next_;
	}
	return *curPos;
}
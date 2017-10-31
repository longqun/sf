#pragma once


template<typename T>
inline void List<T>::selectionSort(ListNodePos(T) pos, int n)
{
	if (n < 2)
		return;
	ListNodePos(T)lastMaxPos = trailer_;
	ListNodePos(T)startPosPre = pos->pre_;
	while (1 < n)
	{
		//record start pos pre if the first one is max!
		ListNodePos(T)max = selectMax(startPosPre->next_, n);
		insertPre(lastMaxPos, remove(max));
		lastMaxPos = lastMaxPos->pre_;
		n--;
	}
}
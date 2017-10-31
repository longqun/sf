#pragma once

template<typename T>
inline void List<T>::sort(SORTMETHOD choice)
{
	sort(first(), size_, choice);
}

template<typename T>
inline void List<T>::sort(ListNodePos(T) pos, int n, SORTMETHOD choice)
{
	switch (choice)
	{
	case INSERTSORT:
		insertSort(pos, n);
		break;
	case SELECTIONSORT:
		selectionSort(pos, n);
		break;

	case MERGESORT:
		mergeSort(pos, n);
	default:
		break;
	}
}

#pragma once
#include "../PQ_ComplHeap/PQ_CompHeap.h"
template<typename T>
inline void Vector<T>::sort(int method)
{
	switch (method)
	{
	case 0:
		bubbleSort(0, size_);
		break;
	case 1:
		selectionSort(0, size_);
		break;
	case 2:
		mergeSort(0, size_);
		break;
	case 3:
		heapSort(0, size_);
		break;
	default:
		break;
	}
}

template<typename T>
inline void Vector<T>::sort(Rank lo, Rank hi)
{
}

template<typename T>
inline void Vector<T>::selectionSort(Rank lo, Rank hi)
{
	while (lo < --hi)
	{
		swap(elem_[max(lo, hi)], elem_[hi]);
	}
}

template<typename T>
inline void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
	while (!bubble(lo, hi--));
}

template<typename T>
inline bool Vector<T>::bubble(Rank lo, Rank hi)
{
	bool sorted = true;
	for (int i = lo; i < hi - 1; i++)
	{
		if (elem_[i] > elem_[i + 1])
		{
			sorted = false;
			swap(elem_[i], elem_[i + 1]);
		}
	}
	return sorted;
}

template<typename T>
inline void Vector<T>::mergeSort(Rank lo, Rank hi)
{
	if (hi - lo < 2)
		return;
	int mid = (lo + hi) >> 1;
	mergeSort(lo, mid);
	mergeSort(mid, hi);
	merge(lo, mid, hi);
}


template<typename T>
inline void Vector<T>::merge(Rank lo, Rank mid, Rank hi)
{
	int preSize = mid - lo;
	T * preData = new T[preSize];
	T* lb = elem_ + lo;
	T* lm = elem_ + mid;
	for (int i = 0; i < preSize; i++)
	{
		preData[i] = lb[i];
	}
	for (int i = 0; i < preSize; )
	{
		if (mid >= hi)
		{
			elem_[lo++] = preData[i++];
		}
		else if (preData[i] < elem_[mid])
		{
			elem_[lo++] = preData[i++];
		}
		else if (preData[i] >= elem_[mid])
		{
			elem_[lo++] = elem_[mid++];
		}
	}
}

template<typename T>
inline void Vector<T>::heapSort(Rank lo, Rank hi)
{
	PQ_ComplHeap<T> h(elem_ + lo, hi - lo);
	while (!h.empty())
	{
		elem_[--hi] = h.delMax();
	}
}

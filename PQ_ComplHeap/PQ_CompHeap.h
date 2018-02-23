#pragma once

#include "../vector/vector.h"
#include "PQ.h"
#include "macro.h"

template<typename T> class PQ_ComplHeap :public PQ<T>, public Vector<T>
{
protected:
	Rank percolateDown(Rank n, Rank i);

	Rank percolateUp(Rank i);

	void heapify(Rank n);

public:

	PQ_ComplHeap() {}
	PQ_ComplHeap(T* A, Rank n)
	{
		copyFrom(A, 0, n);
		heapify(n);
	}

	void insert(T);
	T getMax();
	T delMax();

};

template<typename T>
inline Rank PQ_ComplHeap<T>::percolateDown(Rank n, Rank i)
{
	Rank j;
	while (i != (j = ProperParent(elem_, n, i)))
	{
		swap(elem_[i], elem_[j]);
		i = j;
	}
	return i;
}

template<typename T>
inline Rank PQ_ComplHeap<T>::percolateUp(Rank i)
{
	while (ParentValid(i))
	{
		Rank j = Parent(i);
		if (lt(elem_[i], elem_[j]))
			break;
		swap(elem_[i], elem_[j]);
		i = j;
	}
	return i;
}

template<typename T>
inline void PQ_ComplHeap<T>::insert(T e)
{
	Vector<T>::insert(e);
	percolateUp(size_ - 1);
}

template<typename T>
inline T PQ_ComplHeap<T>::getMax()
{
	return elem_[0];
}

template<typename T>
inline T PQ_ComplHeap<T>::delMax()
{
	T max = elem_[0];
	elem_[0] = elem_[--size_];
	percolateDown(size_, 0);
	return max;
}

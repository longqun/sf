#pragma once

typedef int Rank;
#define DEFAULT_CAPACITY 3


template <typename T>
class Vector
{
protected:
	Rank size_;
	int capacity_;
	T* elem_;
	void copyFrom(T const * a, Rank lo, Rank hi);

	void expand();
	void shrink();

public:
	Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T val = 0);
	Vector(T const * a, int n);
	Vector(T const * a, Rank lo, Rank hi);
	Vector(Vector<T>const &v);
	Vector(Vector<T>const &v, Rank lo, Rank hi);

	~Vector()
	{
		delete elem_;
	}

	Rank size() { return size_; }

	bool empty() { return !size_; }

	Rank find(T const & val) { return find(val, 0, size_); }

	Rank find(T const& val, Rank lo, Rank hi);

	T remove(Rank r);

	int remove(Rank lo, Rank hi);

	T& operator[] (Rank r);

	Vector<T>& operator=(Vector<T>const &vec);

	Rank max(Rank lo, Rank hi);

	Rank insert(T const &  val);

	Rank insert(Rank r, T const& val);

	void traverse(void(*cb)(T const&));

	Rank search(T const &e) { return size_ <= 0 ? -1 : search(e, 0, size_;) };

	Rank search(T const& e, Rank lo, Rank hi);

	void unsort() { unsort(0, size_); };

	void unsort(Rank lo, Rank hi);

	//unsorted
	int deduplicate();

	//sorted
	int uniquify();

	void sort(int method);

	void sort(Rank lo, Rank hi);
};

template<typename T>
inline void Vector<T>::sort(int method)
{
	sort(0, size_);
}

template<typename T>
inline void Vector<T>::sort(Rank lo, Rank hi)
{
}





#include "vector_implementation.h"
#pragma once

#include "../list/list.h"

template <typename T>
class Queue : public List<T>
{
public:
	void enqueue(T const & val) { push_back(val); }
	T dequeue() { return remove(first()); }

	T& fron() { return first()->data_; }
};
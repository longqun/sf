#pragma once

template<typename T>
inline void Vector<T>::expand()
{
	if (size_ < capacity_)
		return;
	if (capacity_ < DEFAULT_CAPACITY)
		capacity_ = DEFAULT_CAPACITY;
	T* oldElem = elem_;
	elem_ = new T[capacity_ <<= 1];
	for (int i = 0; i < size_; i++)
	{
		elem_[i] = oldElem[i];
	}
	delete oldElem;
}
#pragma once


template<typename T>
inline void Vector<T>::shrink()
{
	if (capacity_ < DEFAULT_CAPACITY << 1)
		return;
	if (size_ > capacity_ >> 2)
		return;
	T* oldElem = elem_;
	elem_ = new T[capacity_ >>= 1];
	for (int i = 0; i < size_; i++)
	{
		elem_[i] = oldElem[i];
	}
	delete oldElem;
}
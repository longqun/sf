#pragma once


template<typename T>
inline void List<T>::push_front(T const & t)
{
	header_->insertAsNext(t);
	size_++;
}
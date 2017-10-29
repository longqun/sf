#pragma once


template<typename T>
inline void List<T>::push_back(T const & t)
{
	trailer_->insertAsPre(t);
	size_++;
}
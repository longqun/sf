#pragma once


template<typename T>
inline List<T>::~List()
{
	clear();
	delete header_;
	delete trailer_;
}
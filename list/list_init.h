#pragma once
#include <limits.h> //INT_MIN 
template<typename T>
void List<T>::init()
{
	header_ = new ListNode<T>();
	trailer_ = new ListNode<T>();
	header_->next_ = trailer_;
	trailer_->pre_ = header_;
	size_ = 0;
}
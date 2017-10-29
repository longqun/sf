#pragma once
#include <limits.h> //INT_MIN 
template<typename T>
void List<T>::init()
{
	header_ = new ListNode<T>(INT_MIN);
	trailer_ = new ListNode<T>(INT_MIN);
	header_->next_ = trailer_;
	trailer_->pre_ = header_;
	size_ = 0;
}
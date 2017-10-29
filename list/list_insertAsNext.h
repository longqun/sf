#pragma once


template<typename T>
ListNodePos(T) ListNode<T>::insertAsNext(T const & data)
{
	ListNodePos(T) newNode = new ListNode<T>(data, this, next_);
	next_->pre_ = newNode;
	next_ = newNode;
	return newNode;
}
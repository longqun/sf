#pragma once



template<typename T>
ListNodePos(T) ListNode<T>::insertAsPre(T const & data)
{
	ListNodePos(T)  newNode = new ListNode<T>(data, pre_, this);
	pre_->next_ = newNode;
	pre_ = newNode;
	return newNode;
}
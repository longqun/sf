#pragma once


template<typename T>
T List<T>::remove(ListNodePos(T) rnode)
{
	T ret = rnode->data_;
	rnode->pre_->next_ = rnode->next_;
	rnode->next_->pre_ = rnode->pre_;
	delete rnode;
	size_--;
	return ret;
}
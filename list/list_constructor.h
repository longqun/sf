#pragma once
template<typename T>
List<T>::List(List<T> const & list)
{
	init();
	copyNodes(list->header_->next_, n);
}


template<typename T>
List<T>::List(List<T> const & list, Rank lo, int n)
{
	//assert((lo + n) <= list.size_);
	init();
	copyNodes(list[lo], n);
}


template<typename T>
List<T>::List(ListNodePos(T) pos, int n)
{
	copyNodes(pos, n);
}
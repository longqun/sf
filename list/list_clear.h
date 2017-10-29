#pragma once
template<typename T>
int List<T>::clear()
{
	int oldSize = size_;
	while (size_ > 0)
	{
		remove(header_->next_);
	}
	return oldSize;
}
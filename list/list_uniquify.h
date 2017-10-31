#pragma once


template<typename T>
inline int List<T>::uniquify()
{
	if (size_ < 2)
		return 0;
	ListNodePos(T)curPos = first()->next_;
	int oldSize = size_;
	for (int i = 0; i < size_ - 1; i++)
	{
		if (curPos->data_ == curPos->pre_->data_)
		{
			remove(curPos->pre_);
			i--;
		}
		curPos = curPos->next_;
	}
	return oldSize - size_;
}
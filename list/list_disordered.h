#pragma once


template<typename T>
inline int List<T>::disordered() const
{
	ListNodePos(T) curPos = first();
	int count = 0;
	for (int i = 0; i < size_ - 1; i++)
	{
		if (curPos->data_ > curPos->next_->data_)
		{
			count++;
		}
	}
	return count;
}
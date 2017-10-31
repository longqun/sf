#pragma once


template<typename T>
inline void List<T>::insertSort(ListNodePos(T) pos, int n)
{
	if (n < 2)
		return;
	ListNodePos(T) curPos = pos->next_;
	for (int i = 0; i < n - 1; i++)
	{
		ListNodePos(T) temp = curPos->pre_;
		if (curPos->data_ >= temp->data_)
			curPos = curPos->next_;
		else
		{
			while (curPos->data_ < temp->data_)
			{
				temp = temp->pre_;
			}
			//case  INT_MIN not considered!
			insertNext(temp, curPos->data_);
			ListNodePos(T) delPos = curPos;
			curPos = curPos->next_;
			remove(delPos);
		}
	}
}
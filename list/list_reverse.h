#pragma once
template<typename T>
void List<T>::reverse()
{
	reverseRecurse(header_->next_, header_);
	swap(header_, trailer_);
}

template<typename T>
inline void List<T>::reverseRecurse(ListNodePos(T) curPos, ListNodePos(T) prePos)
{
	if (curPos == NULL)
	{
		prePos->pre_ = NULL;
		return;
	}
	reverseRecurse(curPos->next_, curPos);
	if (!curPos->next_)
	{
		curPos->next_ = prePos;
		prePos->pre_ = curPos;
		//curPos->pre_ = NULL;
		prePos->next_ = NULL;
		return;
	}
}
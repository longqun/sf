#pragma once

template<typename T>
void List<T>::traverse(void(*cb)(T &))
{
	ListNodePos(T) curPos = header_->next_;
	while (curPos != trailer_)
	{
		cb(curPos->data_);
		curPos = curPos->next_;
	}
}

template<typename T>
inline void List<T>::rtraverse(void(*cb)(T &))
{
	ListNodePos(T) curPos = trailer_->pre_;
	while (curPos != header_)
	{
		cb(curPos->data_);
		curPos = curPos->pre_;
	}
}
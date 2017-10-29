#pragma once

template<typename T>
inline void List<T>::traverse(void(*cb)(T &))
{
	ListNodePos(T) curPos = header_->next_;
	while (curPos != trailer_)
	{
		cb(curPos->data_);
		curPos = curPos->next_;
	}
}
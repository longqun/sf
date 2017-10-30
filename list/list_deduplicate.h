#pragma once


template<typename T>
inline void List<T>::deduplicate()
{
	if (size_ < 2)
		return;
	ListNodePos(T) cur = first()->next_;
	for (int i = 0; i < size_ - 1; i++)
	{
		ListNodePos(T) ret = find(cur->data_, i + 1, cur->pre_);
		if (ret)
		{
			//删除之后需要往前挪动一位
			remove(ret);
			i--;
		}
		cur = cur->next_;
	}
}
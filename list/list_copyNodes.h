#pragma once

template<typename T>
void List<T>::copyNodes(ListNodePos(T) pos, int n)
{
	//assert(pos != NULL&&n >= 0);
	while (n-- > 0)
	{
		trailer_->insertAsPre(pos->data_);
		size_++;
		pos = pos->next_;
	}
}
#pragma once

#include "listnode.h"
//#include "assert.h"

template<typename T>
class List
{
public:
	Rank size() { return size_; }
	bool empty() { return size_ == 0 ? true : false; }

	T remove(ListNodePos(T) rnode);

	List() { init(); }
	List(List<T> const& list);
	List(List<T> const& list, Rank lo, int n);
	List(ListNodePos(T) pos, int n);

	T& operator[](Rank n);

	void push_back(T const &t);

	void push_front(T const& t);

	void traverse(void(*cb)(T&));


	ListNodePos(T) first()
	{
		return header_->next_;
	}

	ListNodePos(T) last()
	{
		return trailer_->pre_;
	}

	bool valid(ListNodePos(T) pos);

	~List();

	ListNodePos(T) find(T const& var);
	// trailer_  --> header  for sorted
	ListNodePos(T) find(T const& var, int n, ListNodePos(T) pos);


	ListNodePos(T) search(T const& var);
	// trailer_  --> header  for sorted
	ListNodePos(T) search(T const& var, int n, ListNodePos(T) pos);

	ListNodePos(T) selectMax(ListNodePos(T) pos, int n);

	ListNodePos(T) selectMax();

	//ͳ����������Ԫ�ضԵ�����
	int disordered() const;
protected:
	void init();
	int clear();
	void copyNodes(ListNodePos(T) pos, int n);

private:
	int size_;
	ListNodePos(T) header_;
	ListNodePos(T) trailer_;
};


template<typename T>
inline ListNodePos(T) List<T>::selectMax(ListNodePos(T) pos, int n)
{
	ListNodePos(T) max = pos;
	for (int i = 0; i < n - 1; i++)
	{
		pos = pos->next_;
		if (max->data_ < pos->data_)
			max = pos;
	}
	return max;
}

template<typename T>
inline ListNodePos(T) List<T>::selectMax()
{
	return selectMax(first(),size_);
}



#include "list_implementation.h"


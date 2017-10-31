#pragma once

#include "listnode.h"
//#include "assert.h"

template<typename T>
class List
{
public:
	enum SORTMETHOD
	{
		INSERTSORT = 0,
		SELECTIONSORT = 1,
		MERGESORT = 2
	};

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

	void rtraverse(void(*cb)(T&));


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

	//统计逆序相邻元素对的总数
	int disordered() const;

	void deduplicate();
	//sorted deduplicate
	int uniquify();

	void reverse();

	void reverseRecurse(ListNodePos(T) curPos, ListNodePos(T) prePos);

	void insertPre(ListNodePos(T) pos, T const &val);

	void insertNext(ListNodePos(T) pos, T const &val);

	void sort(SORTMETHOD choice = MERGESORT);

	void sort(ListNodePos(T) pos, int n, SORTMETHOD choice);

	void insertSort(ListNodePos(T) pos, int n);

	void selectionSort(ListNodePos(T) pos, int n);

	void mergeSort(ListNodePos(T) pos, int n);
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
inline void List<T>::mergeSort(ListNodePos(T) pos, int n)
{

}
#include "list_implementation.h"


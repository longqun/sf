#pragma once

#include "quadlistnodeh.h"

typedef int Rank;

template<typename T>
class QuadList
{
private:
	int size_;

	QListNodePosi(T) header_;
	QListNodePosi(T) trailer_;

protected:
	void init();
	int clear();

public:

	QuadList() { init(); }

	~QuadList()
	{
		clear();
		delete header_;
		delete trailer_;
	}

	Rank size() const { return size_; }

	bool empty() const { return size__ <= 0; }

	QListNodePosi(T) first() { return header_->next_; }

	QListNodePosi(T) last() { return trailer_->pre_; }

	bool valid(QListNodePosi(T) pos) { return pos && pos != header_ && pos != trailer_; }

	T remove(QListNodePosi(T) p);

	QListNodePosi(T) insertAfterAbove(const T& e, QListNodePosi(T) p, QListNodePosi(T) b = NULL);

	void traverse(void(*)(T& e));




};

template<typename T>
inline void QuadList<T>::init()
{
	header_ = new QuadList<T>;
	trailer_ = new QuadList<T>;
	header_->next_ = trailer_;
	trailer_->pre_ = header_;
	trailer_->next_ = NULL;

	trailer_->above_ = header_->above_ = NULL;
	trailer_->below_ = header_->below_ = NULL;

	size_ = 0;
}

template<typename T>
inline int QuadList<T>::clear()
{
	int oldSize = size_;
	while (0 < size_)
	{
		remove(header_->next_);
	}
	return oldSize;
}

template<typename T>
inline T QuadList<T>::remove(QListNodePosi(T) p)
{
	size_--;
	p->pre_->next_ = p->next_;
	p->next_->pre_ = p->pre_;


	T e = p->entry_;
	delete p;
	return e;
}

template<typename T>
inline QListNodePosi(T) QuadList<T>::insertAfterAbove(const T & e, QListNodePosi(T) p, QListNodePosi(T) b)
{
	size_++;
	return p->insertAsSuccAbove(e, b);
}

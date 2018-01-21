#pragma once

#include "../list/list.h"
#include "entry.h"
#include "../directory/Dictionary.h"

#include "quadlist.h"


template <typename K, typename V>
class SkipList : public Dictionary<K, V>, public List<QuadList<Entry<K, V>>*>

{

protected:
	bool skipSearch(
		ListNode<QuadList<Entry<K, V>>*>* &qlist,
		QuadListNode<Entry<K, V>>* &p,
		K& k);
public:

	int size()const
	{
		return empty() ? 0 : last()->data->size();
	}

	int level() { return List::size(); }

	bool put(K, V);

	V* get(K k);

	bool remove(K k);

};

template<typename K, typename V>
inline bool SkipList<K, V>::skipSearch(ListNode<QuadList<Entry<K, V>>*>*& qlist, QuadListNode<Entry<K, V>>*& p, K & k)
{
	while (true)
	{
		while (p->next_ && p->next_->entry_.key_ <= k)
		{
			p = p->next_;;
		}
		p = p->pre_;
		if (p->pre_ && p->entry_.key_ == k)
			return true;
		qlist = qlist->next_;
		if (!qlist)			//qlist  ???? qlist->next_
			return false;
		p = (p->pre_) ? p->below_ : qlist->data_->first();
	}

}

template<typename K, typename V>
inline bool SkipList<K, V>::put(K, V)
{
	if (empty())
		insertAsFirst(new QuadList<Entry<K, V>>);
	ListNode<QuadList<Entry<K, V>>*>* qlist = first();

	QuadListNode<Entry<K, V>> * p = qlist->data_->first();

	if (skipSearch(qlist, p, k))
	{
		while (p->below_)
			p = p->below_;
	}
	qlist = last();

	QuadListNode<Entry<K, V>> * b = qlist->data_->insertAfterAbove(e, p);

	while (rand() & 1)
	{
		while (qlist->data_->valid(p) && !p->above_)
			p = p->pre_;
		if (!qlist->data_->valid(p) && !p->above_)
			p = p->pre_;
		if (!qlist->data_->valid(p))
		{
			if (qlist == first())
				insertAsFirst(new QuadList<Entry<K, V>>);
			p = qlist->pre_->data_->first()->pre_;
		}
		else
		{
			p = p->above_;
		}

		qlist = qlist->pre_;

		b = qlist->data_->insertAfterAbove(e, p, b);


	}
	return true;
}

template<typename K, typename V>
inline V * SkipList<K, V>::get(K k)
{
	if (empty())
		return NULL;

	ListNode<QuadList<Entry<K, V>>*>* qlist = first();

	QuadListNode<Entry<K, V>>* p = qlist->data_->first();
	return skipSearch(qlist, p, k) ? &(p->entry_.value_) : NULL;

}

template<typename K, typename V>
inline bool SkipList<K, V>::remove(K k)
{
	if (empty())
		return false;
	ListNode<QuadList<Entry<K, V>>*>* qlist = first();
	QuadListNode<Entry<K, V>>* p = qlist->data_->first();
	if (!skipSearch(qlist, p, k))
		retunr false;
	do
	{
		QuadListNode<Entry<K, V>>* lower = p->below_;
		qlist->data_->remove(p);
		p = lower;
		qlist = qlist->next_;
	} while (qlist->next_);
	while (!empty() && first()->data_->empty())
		QList::remove(first);;
	return true;
}

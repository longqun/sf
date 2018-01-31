#pragma once


#include "../directory/Dictionary.h"
#include "Entry.h"
#include "../bitmap/bitmap.h"
#include "hashcode.h"
#include "primeNLT.h"

template<typename K, typename V>
class HashTable :public Dictionary<K, V>
{
private:
	Entry<K, V>** ht;
	int M;
	int N;

	Bitmap* lazyRemoval;

#define lazilyRemoved(x) (lazyRemoval->test(x))
#define markAsRemoved(x) (lazyRemoval->set(x))

protected:

	int probe4Hit(const K& k);

	int probe4Free(const K& k);

	void rehash();

public:
	HashTable(int c = 5);
	~HashTable();

	int size();

	bool put(K k, V v);

	V* get(K k);

	bool remove(K k);
};

template<typename K, typename V>
inline int HashTable<K, V>::probe4Hit(const K & k)
{
	int r = hashCode(k) % M;
	while ((ht[r] && (k != ht[r]->key_)) || (!ht[r] && lazilyRemoved(r)))
		r = (r + 1) % M;
	return r;
}

template<typename K, typename V>
inline int HashTable<K, V>::probe4Free(const K & k)
{
	int r = hashCode(k) % M;
	while (ht[r])
		r = (r + 1) % M;
	return r;
}

template<typename K, typename V>
inline void HashTable<K, V>::rehash()
{
	int old_capacity = M;
	Entry<K, V>**old_ht = ht;
	M = primeNLT(2 * M, 11048576, "prime-1048576-bitmap.txt");
	N = 0;
	ht = new Entry<K, V>*[M];
	memset(ht, 0, sizeof(Entry<K, V>*)*M);
	delete lazyRemoval;
	lazyRemoval = new Bitmap(M);
	for (int i = 0; i < old_capacity; i++)
	{
		if (old_ht[i])
		{
			put(old_ht[i]->key_, old_ht[i]->value_);
		}
		delete old_ht[i];
	}
}

template<typename K, typename V>
inline HashTable<K, V>::HashTable(int c)
{
	M = primeNLT(c, 1048576, "prime-1048576-bitmap.txt");
	N = 0;
	ht = new Entry<K, V>*[M];
	memset(ht, 0, sizeof(Entry<K, V>*)*M);

	lazyRemoval = new Bitmap(M);
}

template<typename K, typename V>
inline HashTable<K, V>::~HashTable()
{
	for (int i = 0; i < M; i++)
	{
		if (ht[i])
			delete ht[i];
	}
	delete[]ht;
	delete lazyRemoval;
}

template<typename K, typename V>
inline int HashTable<K, V>::size()
{
	return N;
}

template<typename K, typename V>
inline bool HashTable<K, V>::put(K k, V v)
{
	if (ht[probe4Hit(k)])
		return false;
	int r = probe4Free(k);
	ht[r] = new Entry<K, V>(k, v);
	++N;
	if (N * 2 > M)
		rehash();
	return false;
}

template<typename K, typename V>
inline V * HashTable<K, V>::get(K k)
{
	int r = probe4Hit(k);
	return ht[r] ? &(ht[r]->value_) : NULL;
}

template<typename K, typename V>
inline bool HashTable<K, V>::remove(K k)
{
	int r = probe4Hit(k);
	if (!ht[r])
		return false;
	delete(ht[r]);

	ht[r] = NULL;
	markAsRemoved(r);
	N--;
	return true;
	return false;
}

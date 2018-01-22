#pragma once


#include "../directory/Dictionary.h"
#include "../bitmap/bitmap.h"
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

	int size() { return N; }

	bool put(K k, V v);

	V* get(K k);

	bool remove(K k);
};

template<typename K, typename V>
inline int HashTable<K, V>::probe4Hit(const K & k)
{
	return 0;
}

template<typename K, typename V>
inline int HashTable<K, V>::probe4Free(const K & k)
{
	return 0;
}

template<typename K, typename V>
inline void HashTable<K, V>::rehash()
{
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
inline bool HashTable<K, V>::put(K k, V v)
{
	return false;
}

template<typename K, typename V>
inline V * HashTable<K, V>::get(K k)
{
	return NULL;
}

template<typename K, typename V>
inline bool HashTable<K, V>::remove(K k)
{
	return false;
}

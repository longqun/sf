#pragma once

template <typename K, typename V>
struct Entry
{
	K key_;
	V value_;
	Entry(K k, V v) :key_(k), value_(v)
	{
	}

	Entry(const Entry<K, V>& e) :key_(e.key_), value_(e.value_)
	{

	}

	bool operator<(Entry<K, V>&e)
	{
		return key_ < e.key_;
	}

	bool operator>(Entry<K, V>&e)
	{
		return key_ > e.key_;
	}

	bool operator ==(Entry<K, V>&e)
	{
		return key_ == e.key_;
	}
};
#pragma once

template <typename K, typename V> struct Entry 
{
	K key; V value;

	Entry(K k = K(), V v = V()) : key(k), value(v) {}; //默认构造函数
	Entry(Entry<K, V> const& e) : key(e.key), value(e.value) {}; //基于克隆的构造函数
	bool operator< (Entry<K, V> const& e) { return key <  e.key; }  //比较器：小于
	bool operator> (Entry<K, V> const& e) { return key >  e.key; }  //比较器：大于
	bool operator== (Entry<K, V> const& e) { return key == e.key; } //判等器：等于
	bool operator!= (Entry<K, V> const& e) { return key != e.key; } //判等器：不等于
};
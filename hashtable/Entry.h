#pragma once


template <typename K, typename V> struct Entry { //词条模板类
	K key_; V value_; //关键码、数值
	Entry(K k = K(), V v = V()) : key_(k), value_(v) {}; //默认构造函数
	Entry(Entry<K, V> const& e) : key_(e.key_), value_(e.value_) {}; //基于克隆的构造函数
	bool operator< (Entry<K, V> const& e) { return key_ <  e.key_; }  //比较器：小于
	bool operator> (Entry<K, V> const& e) { return key_ >  e.key_; }  //比较器：大于
	bool operator== (Entry<K, V> const& e) { return key_ == e.key_; } //判等器：等于
	bool operator!= (Entry<K, V> const& e) { return key_ != e.key_; } //判等器：不等于
}; //得益于比较器和判等器，从此往后，不必严格区分词条及其对应的关键码
#pragma once


template <typename K, typename V> struct Entry { //����ģ����
	K key_; V value_; //�ؼ��롢��ֵ
	Entry(K k = K(), V v = V()) : key_(k), value_(v) {}; //Ĭ�Ϲ��캯��
	Entry(Entry<K, V> const& e) : key_(e.key_), value_(e.value_) {}; //���ڿ�¡�Ĺ��캯��
	bool operator< (Entry<K, V> const& e) { return key_ <  e.key_; }  //�Ƚ�����С��
	bool operator> (Entry<K, V> const& e) { return key_ >  e.key_; }  //�Ƚ���������
	bool operator== (Entry<K, V> const& e) { return key_ == e.key_; } //�е���������
	bool operator!= (Entry<K, V> const& e) { return key_ != e.key_; } //�е�����������
}; //�����ڱȽ������е������Ӵ����󣬲����ϸ����ִ��������Ӧ�Ĺؼ���
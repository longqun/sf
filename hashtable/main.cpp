// hashtable.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "hashtable.h"
#include "iostream"
using namespace std;
int main()
{
	HashTable<int, int>hash;
	hash.put(1, 456);
	cout << *hash.get(1);
	hash.remove(1);
	cout << hash.size();
	cout << hash.get(1);;
    return 0;
}


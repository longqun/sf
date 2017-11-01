// list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "listnode.h"
#include "iostream"
#include "list.h"
typedef void(*visitCb)(int &val);



using namespace std;

template<typename T>
void visitCB(T& val)
{
	cout << val << endl;
}

int main()
{
	List<int>list;
	for (int i = 0; i < 10; i++)
	{
		list.push_back(10-i);
	}
	//cout << list.find(5)->data_;
	
	//list.reverse();
	//list.traverse(visitCB);
	list.sort(List<int>::MERGESORT);
	list.traverse(visitCB);
	return 0;
}


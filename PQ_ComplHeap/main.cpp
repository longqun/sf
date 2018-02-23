// PQ_ComplHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PQ_CompHeap.h"
#include "iostream"
using namespace std;
void traver(const int& val)
{
	cout << val << std::endl;
}
int main()
{
	PQ_ComplHeap<int> heap;
	heap.insert(90);
	heap.insert(50);
	heap.insert(70);
	heap.insert(800);
	heap.insert(10);
	heap.insert(0);
	heap.insert(9600);
	while (!heap.empty())
	{
		cout << heap.delMax() << endl;;
	}
    return 0;
}


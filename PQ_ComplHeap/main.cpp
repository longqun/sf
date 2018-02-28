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

	int arr[10];
	arr[0] = 2;
	arr[1] = 1;
	arr[2] = 6;
	arr[3] = 3;
	arr[4] = 9;
	arr[5] = 7;
	arr[6] = 4;
	arr[7] = 8;
	arr[8] = 5;
	arr[9] = 0;

	PQ_ComplHeap<int> heap(arr, 10);
	while (!heap.empty())
	{
		cout << heap.delMax() << std::endl;;
	}
	return 0;
}


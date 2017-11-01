// queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "queue.h"
#include "iostream"
using namespace std;
int main()
{
	Queue<int>q;
	q.enqueue(1);
	cout<<q.dequeue();
    return 0;
}


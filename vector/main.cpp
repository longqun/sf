// vector.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector.h"
#include "iostream"
using  namespace std;

template<typename T>
void visitCb(T const& val)
{
	cout << val << endl;
}

int main()
{
	Vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.insert(i);
	vec.remove(0);
	vec.traverse(visitCb);
    return 0;
}


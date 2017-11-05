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
	/*vec.insert(6);
	vec.insert(3);
	vec.insert(4);
	vec.insert(7);
	vec.insert(1);
	vec.insert(5);
	vec.insert(8);
	vec.insert(4);*/
	for (int i = 10; i > 0; i--)
	{
		vec.insert(i);
	}
	vec.sort(2);
	vec.traverse(visitCb);
    return 0;
}


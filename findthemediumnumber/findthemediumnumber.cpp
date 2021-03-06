// findthemediumnumber.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../vector/vector.h"
#include "iostream"
using namespace std;
//查找出现最多的中位数
// 1 2 3 4 4 4 4 5 6    没有中位数
// 1 2 3 4 4 4 4 4 5 6   中位数为4
//类似于dp? 遍历一遍至少可以得到一个值可能存在为中位数

template<typename T> T majEleCandidate(Vector<T>& vec)
{
	int count = 0;
	T maj;
	for (int i = 0; i < vec.size(); i++)
	{
		if (count == 0)
		{
			maj = vec[i];
			count = 1;
		}
		else
		{
			vec[i] == maj ? count++ : count--;
		}
	}
	return maj;
}

template <typename T> bool majEleCheck(Vector<T>&vec, T maj)
{
	int count = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == maj)
			count++;
	}
	return 2 * count > vec.size();
}

template <typename T>
bool majority(Vector<T>& vec, T &maj)
{
	maj = majEleCandidate(vec);
	return majEleCheck(vec, maj);
}

template <typename T>
void quickSelect(Vector<T>&vec, int k)
{
	for (Rank lo = 0, hi = vec.size() - 1; lo < hi;)
	{
		T x = vec[lo];
		Rank left = lo;
		Rank right = hi;
		while (left < right)
		{
			while (left<right && vec[right] > x)
			{
				right--;
			}
			vec[left] = vec[right];
			while (left < right && vec[left] < x)
			{
				left++;
			}
			vec[right] = vec[left];
		}

		vec[left] = x;
		if (left >= k)
		{
			hi = k - 1;
		}

		if (right <= k)
		{
			lo = k + 1;
		}
	}
	cout << vec[k] << endl;;

}


int main()
{
	Vector<int> vec;
	for (int i = 1; i < 101; i++)
	{
		vec.insert(i);
	}
	quickSelect(vec, 0);
	//cout << majority(vec, a);
	return 0;
}


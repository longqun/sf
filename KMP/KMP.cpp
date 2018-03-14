// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "iostream"
using namespace std;

//force -1
int matchV1(char* p, char* t)
{
	size_t tlen = strlen(t), i = 0;
	size_t plen = strlen(p), j = 0;

	while (i < tlen&&j < plen)
	{
		if (t[i] != p[j])
		{
			i -= (j - 1);
			j = 0;
		}
		else
		{
			i++;
			j++;
		}
	}
	return i;
}

int matchV2(char* p, char* t)
{
	size_t n = strlen(t), i = 0;
	size_t m = strlen(p), j = 0;
	for (i = 0; i < n - m + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (t[i + j] != p[j])
				break;
		}
		if (j >= m)
			break;
	}
	return i;
}

int * buildNext(char* p)
{
	size_t m = strlen(p), j = 0;
	int * N = new int[m];
	int t = N[0] = -1;
	while (j < m - 1)
	{
		if (0 > t || p[t] == p[j])
		{
			t++;
			j++;
			N[j] = t;
		}
		else
		{
			t = N[t];
		}
	}
	return N;
}

//kmp
int matchV3(char*p, char* t)
{
	int  n = strlen(t), i = 0;
	int m = strlen(p), j = 0;

	int * next = buildNext(p);

	while (i < n &&j < m)
	{
		if (0 > j || t[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	cout << i << "   " << j << endl;;
	delete[]next;
	return i-j;

}


int main()
{
	char * text = "12334423eqwscagsfzcvczbnhfdgdsrrerw123eqweqwsadasdsazxcxcfggggyiop";
	char * p = "srrerw123";
	
	cout << matchV3(p,text);

	return 0;
}


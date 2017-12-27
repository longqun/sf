// avl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "avl.h"
#include "iostream"
using namespace std;

void visit(const int& val)
{
	cout << val << endl;
}

int main()
{
	AVL<int> avlTree;
	avlTree.insert(16);
	avlTree.insert(3);

	avlTree.insert(7);
	avlTree.insert(11);
	avlTree.insert(9);
	avlTree.insert(26);
	avlTree.insert(18);

	avlTree.remove(11);
	avlTree.remove(26);
	avlTree.remove(18);
	avlTree.travelLevelOrder(visit);
	return 0;
}


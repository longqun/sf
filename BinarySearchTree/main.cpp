// BinarySearchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "bst.h"
#include "iostream"
using namespace std;

void visit(const int& val)
{
	cout << val << endl;
}

int main()
{
	BST<int> bst;
	bst.insert(36);
	bst.insert(27);
	bst.insert(6);
	bst.insert(58);
	bst.insert(53);
	bst.insert(69);
	bst.insert(64);
	bst.insert(40);
	bst.insert(46);

	bst.remove(69);
	bst.remove(36);
	bst.travelLevelOrder(visit);
    return 0;
}


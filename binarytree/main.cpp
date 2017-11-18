// binarytree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "binary-tree.h"
#include "iostream"
using namespace std;

void visit(const char& val)
{
	cout << val << endl;
}


int main()
{
	BinaryTree<char>bt;

	BinaryNodePos(char) root = bt.insertAsRoot('i');
	BinaryNodePos(char) d = bt.insertAsLeft(root, 'd');
	BinaryNodePos(char) c = bt.insertAsLeft(d, 'c');
	BinaryNodePos(char) a = bt.insertAsLeft(c, 'a');
	BinaryNodePos(char) b = bt.insertAsRight(a, 'b');
	BinaryNodePos(char) h = bt.insertAsRight(d, 'h');
	BinaryNodePos(char) f = bt.insertAsLeft(h, 'f');
	BinaryNodePos(char)e = bt.insertAsLeft(f, 'e');
	BinaryNodePos(char)g = bt.insertAsRight(f, 'g');


	BinaryNodePos(char) l = bt.insertAsRight(root, 'l');

	BinaryNodePos(char) k = bt.insertAsLeft(l, 'k');
	BinaryNodePos(char) j = bt.insertAsLeft(k, 'j');

	BinaryNodePos(char) n = bt.insertAsRight(l, 'n');
	BinaryNodePos(char) m = bt.insertAsLeft(n, 'm');
	BinaryNodePos(char) p = bt.insertAsRight(n, 'p');
	BinaryNodePos(char) o = bt.insertAsLeft(p, 'o');


	/*BinaryTree<char>* bt1 = new BinaryTree<char>;
	bt1->insertAsRoot('z');

	bt.attachAsRight(b, bt1);

	bt.secode(l)->travePreOrder(visit);
	*/
	bt.travePreOrder(visit);
	return 0;
}


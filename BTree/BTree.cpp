// BTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "btree.h"

int main()
{
	
	BTree<int> bt;
	
	bt.insert(53);
	bt.printBtree();
	bt.insert(36);
	bt.printBtree();
	bt.insert(77);
	bt.printBtree();
	bt.insert(89);
	bt.printBtree();
	bt.insert(19);
	bt.printBtree();
	bt.insert(41);
	bt.printBtree();
	bt.insert(51);
	bt.printBtree();
	bt.insert(64);
	bt.printBtree();
	bt.insert(75);
	bt.printBtree();
	bt.insert(79);
	bt.printBtree();
	bt.insert(84);
	bt.printBtree();
	bt.insert(97);
	bt.printBtree();
	
	
	bt.remove(41);
	bt.remove(53);
	bt.remove(75);
	bt.remove(84);
	bt.remove(51);
	
	bt.printBtree();
    return 0;
}


// GraphMatrix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "graphmatrix.h"



int main()
{
	GraphMatrix<char, int>grap;
	grap.insert('A');
	grap.insert('B');
	grap.insert('C');
	grap.insert('D');
	grap.insert('E');
	grap.insert('F');
	grap.insert('G');
	grap.insert('S');

	grap.insert(0,0,0,2);
	grap.insert(0,0,0,4);

	grap.insert(0, 0, 2, 1);
	grap.insert(0, 0, 3, 1);

	grap.insert(0, 0, 4, 5);
	grap.insert(0, 0, 4, 6);

	grap.insert(0, 0, 6, 1);
	grap.insert(0, 0, 6, 5);

	grap.insert(0, 0, 7, 0);

	grap.insert(0, 0, 7, 2);

	grap.insert(0, 0, 7, 3);

	int i = 0;
	grap.bfs(7);
    return 0;
}


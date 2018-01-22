#pragma once
#include "../bitmap/bitmap.h"

int primeNLT(int c, int n, char* file) {
	Bitmap B(file, n);
	while (c < n)
		if (B.test(c)) c++;
		else return c;
		return c;
}
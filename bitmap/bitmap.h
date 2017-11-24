#pragma once
#include "../vector/vector.h"
#include "string.h"
#include "stdio.h"
#pragma warning(disable : 4996 4800)


class Bitmap
{
private:
	char *mem_;
	int size_;

protected:
	void init(int n);

	void expand(int k)
	{
		if (k < 8 * size_) return; 
		int oldN = size_; char* oldM = mem_;
		init(2 * k); 
		memcpy_s(mem_, size_, oldM, oldN); delete[] oldM; 
	}
public:
	Bitmap(int n = 8)
	{
		init(8);
	}

	Bitmap(char* file, int n = 8)
	{
		init(n);
		FILE* fp = fopen(file, "r");
		fread(mem_, sizeof(char), n, fp);
		fclose(fp);
	}

	~Bitmap()
	{
		delete[]mem_;
		mem_ = NULL;
	}
public:
	void set(int i);
	void clear(int i);
	bool test(int i);

	void dump(char *file)
	{
		FILE* fp = fopen(file, "w");
		fwrite(mem_, sizeof(char), size_, fp);
		fclose(fp);
	}

	char* bits2string(int n)
	{
		expand(n - 1);
		char* s = new char[n + 1];
		s[n] = '\0';
		for (int i = 0; i < n; i++)
		{
			s[i] = test(i) ? '1' : '0';
		}
		return s;
	}



};

inline void Bitmap::init(int n)
{
	mem_ = new char[size_ = (n + 7) / 8];
	memset(mem_, 0, size_);
}

inline void Bitmap::set(int i)
{
	expand(i);
	mem_[i >> 3] |= (0x80 >> (i & 0x07));
}

void Bitmap::clear(int i)
{
	expand(i);
	mem_[i >> 3] &= ~(0x80 >> (i & 0x07));
}

inline bool Bitmap::test(int i)
{
	expand(i);
	return mem_[i >> 3] & (0x80 >> (i & 0x07));
}

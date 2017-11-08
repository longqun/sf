#pragma once
#include "stack.h"
struct Queen
{
	int x_, y_;
	bool operator==(const Queen& q)
	{
		return q.x_ == x_ || q.y_ == y_ || (x_ + y) == (q.x_ + q.y_) || (x_ - y) == (q.x_ - q.y_);
	}

	bool operator!=(const Queen &q)
	{
		return operator==(q);
	}
	Queen(int x, int y) :x_(x), y_(y)
	{
	}
};

/*void placeQueen(int n)
{
	Stack<Queen>s;
	Queen q(0, 0);
	s.push(q);
	do
	{
		if (q.y_ >= n || s.size() > n)
		{
			q=s.pop();
			q.y_++;
		}
		else
		{
			
		}
	} while (true);
}*/

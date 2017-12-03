#pragma once

#include "../vector/vector.h"
#include "../graph/graph.h"
#include "limits.h"
#include "../queue/queue.h"

template <typename Tv>
struct Vertex
{
	Tv data_;
	int inDegree_;
	int outDegree_;
	VStatus status_;
	int dTime_;
	int fTime_;
	int parent_;
	int priority_;
	Vertex(Tv const& d = (Tv)0) : data_(d), inDegree_(0), outDegree_(0), status_(UNDISCOVERED), dTime_(-1),
		fTime_(-1), parent_(-1), priority_(INT_MAX)
	{
		INT_MAX;
	}
};

template <typename Te>struct Edge
{
	Te data_;
	int weight_;
	EType type_;
	Edge(Te const&d, int w) :data_(d), weight_(w), type_(UNDETERMINED)
	{}
};

template
<typename Tv, typename Te>
class GraphMatrix :public Graph<Tv, Te>
{
private:
	Vector<Vertex<Tv> >vertexList_;
	Vector<Vector<Edge<Te>*> > edgeList_;

public:
	GraphMatrix() { n = e = 0; };
	~GraphMatrix()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//delete 0 is safe but do nothing
				delete edgeList_[i][j];
			}
		}
	}

	virtual Tv& vertex(int i) { return vertexList_[i].data_; }

	virtual int inDegree(int i) { return vertexList_[i].inDegree_; }

	virtual int outDegree(int i) { return vertexList_[i].outDegree_; }

	virtual int firstNbr(int i) { return nextNbr(i, n); }

	virtual VStatus& status(int i) { return vertexList_[i].status_; }

	virtual int& dTime(int i)
	{
		return vertexList_[i].dTime_;
	}

	virtual int& fTime(int i)
	{
		return vertexList_[i].fTime_;
	}

	virtual int& parent(int i)
	{
		return vertexList_[i].parent_;
	}

	virtual int& priority(int i)
	{
		return vertexList_[i].priority_;
	}

	virtual EType& type(int i, int j) { return edgeList_[i][j]->type_; }

	virtual Te& edge(int i, int j) { return edgeList_[i][j]->data_; }

	virtual int& weight(int i, int j) { return edgeList_[i][j]->weight_; }

	virtual int insert(Tv const&vertex)
	{
		for (int i = 0; i < n; i++)
		{
			edgeList_[i].insert(NULL);
		}
		n++;
		edgeList_.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*)NULL));
		return vertexList_.insert(Vertex<Tv>(vertex));
	}

	virtual Tv remove(int i)
	{
		for (int j = 0; j < n; j++)
		{
			if (exists(i, j))
			{
				delete edgeList_[i][j];
				//edgeList_[i][j] = NULL;
				vertexList_[j].inDegree_--;
			}
		}
		edgeList_.remove(i);
		n--;
		Tv ret = vertex(i);
		vertexList_.remove(i);

		for (int j = 0; j < n; j++)
		{
			if (Edge<Te>*e = edgeList_[j].remove(i))
			{
				delete e;
				vertexList_[j].outDegree_--;
			}
		}
		return ret;
	}

	virtual int nextNbr(int i, int j)
	{
		while (j > -1 && !exists(i, --j));
		return j;
	}

	virtual bool exists(int i, int j)
	{
		return i >= 0 && j >= 0 && (i < n) && (j < n) && edgeList_[i][j];
	}

	virtual void insert(Te const& edge, int weight, int i, int j)
	{
		if (exists(i, j))
			return;
		edgeList_[i][j] = new Edge<Te>(edge, weight);
		e++;
		vertexList_[i].outDegree_++;
		vertexList_[j].inDegree_++;
	}

	virtual Te remove(int i, int j)
	{
		Te ret = edge(i, j);
		delete edgeList_[i][j];
		edgeList_[i][j] = NULL;
		e--;
		vertexList_[i].outDegree_--;
		vertexList_[j].inDegree_--;
		return ret;
	}

	//whole bfs
	void bfs(int start)
	{
		int cur = start;
		reset();
		int time = 0;
		do
		{
			if (status(cur) == UNDISCOVERED)
				BFS(cur, time);
		} while (start != (cur = (++cur%n)));
	}

	//one bfs
	void BFS(int start, int& time)
	{
		printf("begin BFS \n");
		Queue<int> q;
		q.enqueue(start);
		status(start) = DISCOVERED;
		printf("visit <<%c  \n", vertex(start));
		while (!q.empty())
		{
			int ver = q.dequeue();
			dTime(ver) = ++time;
			for (int nextVer = firstNbr(ver); nextVer > -1; nextVer = nextNbr(ver, nextVer))
			{
				if (status(nextVer) == UNDISCOVERED)
				{
					q.enqueue(nextVer);
					status(nextVer) = DISCOVERED;
					printf("visit <<%c  \n", vertex(nextVer));
					parent(nextVer) = ver;
					type(ver, nextVer) = TREE;
				}
				else
				{
					type(ver, nextVer) = CROSS;
				}
			}
			status(ver) = VISITED;
		}
		printf("end BFS \n");
	}

	void dfs(int s)
	{
		reset();
		int time = 0;
		int v = s;

		do
		{
			if (status(v) == UNDISCOVERED)
			{
				DFS(v, time);
			}
		} while (s != (v = (++v) % n));

	}

	void DFS(int start, int& time)
	{
		printf("begin BFS\n");
		Stack<int>s;
		status(start) = DISCOVERED;
		s.push(start);
		printf("dfs << %c \n", vertex(start));
		dTime(start) = ++time;
		while (!s.empty())
		{
			int top = s.top();
			bool found = false;
			for (int u = firstNbr(top); u > -1; u = nextNbr(top, u))
			{
				if (status(u) == UNDISCOVERED)
				{
					status(u) = DISCOVERED;
					s.push(u);
					parent(u) = top;
					printf("dfs << %c \n", vertex(u));
					found = true;;
					type(top, u) = TREE;
					break;
				}
				else if (status(u) == DISCOVERED)
				{
					type(top, u) = BACKWARD;
				}
				else if (status(u) == VISITED)
				{
					type(top, u) = (dTime(top) < dTime(u) ? FORWARD : CROSS);
				}
			}

			if (!found)
			{
				status(top) = VISITED;
				fTime(top) = ++time;
				s.pop();
			}

		}
		printf("end BFS\n");
	}

	//DFS stack is the tsort order
	void tSort(int s)
	{
		Stack<Tv>vertexStack;
		reset();
		int time = 0;
		int v = s;

		do
		{
			if (status(v) == UNDISCOVERED)
			{
				TSort(v, time, &vertexStack);
			}
		} while (s != (v = (++v) % n));
		for (int i = 0; i < vertexStack.size(); i++)
		{
			printf("the vertex is %c \n", vertex(vertexStack[i]));
		}
	}

	void TSort(int start, int &time, Stack<Tv>*vertexStack)
	{
		Stack<int>s;
		status(start) = DISCOVERED;
		s.push(start);
		dTime(start) = ++time;
		while (!s.empty())
		{
			int top = s.top();
			bool found = false;
			for (int u = firstNbr(top); u > -1; u = nextNbr(top, u))
			{
				if (status(u) == UNDISCOVERED)
				{
					status(u) = DISCOVERED;
					s.push(u);
					parent(u) = top;
					found = true;;
					type(top, u) = TREE;
					break;
				}
				else if (status(u) == DISCOVERED)
				{
					type(top, u) = BACKWARD;
				}
				else if (status(u) == VISITED)
				{
					type(top, u) = (dTime(top) < dTime(u) ? FORWARD : CROSS);
				}
			}

			if (!found)
			{
				status(top) = VISITED;
				vertexStack->push(top);
				fTime(top) = ++time;
				s.pop();
			}

		}

	}

};

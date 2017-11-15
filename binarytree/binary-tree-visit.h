#pragma once
#include "binary-node.h"
#include "../stack/stack.h"
#include "binary-define.h"
template<typename T, typename VST>
static void traverPre_Func2(BinaryNodePos(T) pos, VST& visit)
{
	Stack<BinaryNode<T>*>s;
	if (pos != NULL)
		s.push(pos);
	BinaryNodePos(T) cur = NULL;
	while (!s.empty())
	{
		cur = s.pop();

		while (cur)
		{
			if (cur->right_)
				s.push(cur->right_);
			visit(cur->data_);
			cur = cur->left_;
		}
	}
};

//contains error
template<typename T, typename VST>
static void traverPre_Func1(BinaryNodePos(T) pos, VST& visit)
{
	while (true)
	{
		while (pos)
		{
			visit(pos->data_);
			if (pos->left_ != NULL)
				pos = pos->left_;
			else if (pos->right_ != NULL)
			{
				pos = pos->right_;
			}
			else
			{
				if (IsRightChild(pos))
				{
					pos = pos->parent_->parent_;
					while (pos&&pos->right_ == NULL)
						pos = pos->parent_;
					if (pos)
						pos = pos->right_;
				}
				else if (IsLeftChild(pos))
				{
					while (pos)
					{
						if (pos->parent_->right_)
						{
							pos = pos->parent_->right_;
							break;
						}
						else
						{
							pos = pos->parent_;
						}
					}
				}
			}

		}
	}
};


template<typename T, typename VST>
static void traverInorder_Func1(BinaryNodePos(T) pos, VST& visit)
{
	Stack<BinaryNodePos(T)> s;
	while (true)
	{
		while (pos)
		{
			s.push(pos);
			pos = pos->left_;
		}
		if (s.empty())
			return;
		pos = s.pop();
		visit(pos->data_);
		pos = pos->right_;
	}
}

//using no stack
template<typename T, typename VST>
static void traverInorder_Func2(BinaryNodePos(T) pos, VST& visit)
{

	while (pos->left_)
	{
		pos = pos->left_;
	}
	while (true)
	{
		visit(pos->data_);
		pos = pos->succ();
		if (!pos)
			return;
	}
	return;
}

template<typename T>
static void traverStack(Stack<BinaryNodePos(T)>& s)
{
	while (BinaryNodePos(T) x = s.top())
	{
		if (HasLeftChild(x))
		{
			if (HasRightChild(x))
				s.push(x->right_);
			s.push(x->left_);
		}
		else
			s.push(x->right_);
	}
	//for NULL
	s.pop();
}

template<typename T, typename VST>
static void traverPostRrder_Func(BinaryNodePos(T) pos, VST& visit)
{
	Stack<BinaryNodePos(T)>s;
	if (pos)
		s.push(pos);
	
	while (!s.empty())
	{
		if (s.top() != pos->parent_)
		{
			traverStack(s);
		}
		pos = s.pop();
		visit(pos->data_);
	}
}
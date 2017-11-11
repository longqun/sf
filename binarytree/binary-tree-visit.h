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
		if (cur->right_)
			s.push(cur->right_);
		while (cur)
		{
			visit(cur->data_);
			cur = cur->left_;
		}
	}
};


template<typename T, typename VST>
static void traverPre_Func1(BinaryNodePos(T) pos, VST& visit)
{
	while (true)
	{
		while (pos)
		{
			visit(pos);

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
			}

		}
	}
};



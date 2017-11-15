#pragma once
template<typename T>
inline BinaryNodePos(T) BinaryNode<T>::succ()
{
	BinaryNodePos(T) cur = this;
	if (right_)
	{
		cur = cur->right_;
		while (cur->left_)
		{
			cur = cur->left_;
		}
	}
	else
	{
		while (IsRightChild(cur))
		{
			cur = cur->parent_;
		}
		cur = cur->parent_;
	}

	return cur;
}
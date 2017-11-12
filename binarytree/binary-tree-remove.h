#pragma once
#include "binary-node.h"
#include "binary-define.h"


template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
static int removeAt(BinaryNodePos(T) x) { //assert: x为二叉树中的合法位置
	//using stack with no recuse
	if (!x)
		return 0;
	int ret = removeAt(x->left_) + removeAt(x->right_) + 1;
	delete x;
	return ret;
}

// remove ths pos and child
//pos is valid
template<typename T>
inline int BinaryTree<T>::remove(BinaryNodePos(T) pos)
{
	if (!pos)
		return 0;
	FromParentTo(pos) = NULL;
	updateHeightAbove(pos->parent_);
	int n = removeAt(pos);
	size_ -= n;
	return n;
}
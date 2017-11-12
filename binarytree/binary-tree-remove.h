#pragma once
#include "binary-node.h"
#include "binary-define.h"


template <typename T> //ɾ����������λ��x���Ľڵ㼰���������ر�ɾ���ڵ����ֵ
static int removeAt(BinaryNodePos(T) x) { //assert: xΪ�������еĺϷ�λ��
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
#pragma once


#define IsRoot(x) ((x)&&(!(x)->parent_))

#define IsLeftChild(x) ((x)&&!(IsRoot(x))&&(x)->parent_->left_==(x))

#define IsRightChild(x) ((x)&&!IsRoot(x)&&(x)->parent_->right_==(x))

#define HasParent(x) ((x)&&(x)->parent_)

#define HasLeftChild(x) ((x)&&(x)->left_)

#define HasRightChild(x) ((x)&&(x)->right_)

#define HasChild(x) ((x)&&((x)->left_||(x)->right_))

#define HasBothChild(x) ((x)&&(x)->left_&&(x)->right_)

#define IsLeaf(x) ((x)&&!HasChild(x))

#define sibling(p) (IsLeftChild(p)?(p)->parent_->right_:(p)->parent_->left)

#define FromParentTo(x)		\
( IsRoot(x) ? root_ : ( IsLeftChild(x) ? (x)->parent_->left_ : (x)->parent_->right_ ) )
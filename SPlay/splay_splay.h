#pragma once
template<typename NodePos>
void attachAsLeftChild(NodePos p, NodePos lc)
{
	if (p)
		p->left_ = lc;
	if (lc)
		lc->parent_ = p;
}

template<typename NodePos>
void attachAsRightChild(NodePos p, NodePos rc)
{
	if (p)
		p->right_ = rc;
	if (rc)
		rc->parent_ = p;
}


template<typename T>
inline BinaryNodePos(T) SPlay<T>::splay(BinaryNodePos(T) v)
{
	BinaryNodePos(T) p = NULL;
	BinaryNodePos(T) g = NULL;
	while ((p = v->parent_) && (g = p->parent_))
	{
		BinaryNodePos(T) gg = g->parent_;
		if (IsLeftChild(v))
		{
			if (IsLeftChild(p))
			{
				attachAsLeftChild(g, p->right_);
				attachAsRightChild(p, g);
				attachAsLeftChild(g, v->right_);
				attachAsRightChild(v, p);
			}
			else
			{
				attachAsLeftChild(p, v->right_);
				attachAsRightChild(g, v->left_);
				attachAsLeftChild(v, g);
				attachAsRightChild(v, p);
			}
		}
		else
		{
			if (IsRightChild(p))
			{
				attachAsRightChild(p, v->left_);
				attachAsRightChild(g, v->right_);
				attachAsLeftChild(p, g);
				attachAsLeftChild(v, p);
			}
			else
			{
				attachAsRightChild(p, v->left_);
				attachAsLeftChild(g, v->right_);
				attachAsRightChild(v, g);
				attachAsLeftChild(v, p);
			}
		}

		if (!gg)
		{
			v->parent_ = NULL;
		}
		else
		{
			if (IsLeftChild(g))
				attachAsLeftChild(gg, v);
			else
				attachAsRightChild(gg, v);
		}
		updateHeight(g);
		updateHeight(p);
		updateHeight(v);
	}

	if (p)
	{
		if (IsLeftChild(v))
		{
			attachAsLeftChild(p, v->right_);
			attachAsRightChild(v, p);
		}
		else
		{
			attachAsRightChild(p, v->left_);
			attachAsLeftChild(v, p);
		}
		updateHeight(p);
		updateHeight(v);
	}
	v->parent_ = NULL;
	return v;
}
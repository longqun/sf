#pragma once



template<typename T>
inline T & Vector<T>::operator[](Rank r)
{
	return elem_[r];
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T> const & vec)
{
	if (elem_)
		delete elem_;
	copyFrom(vec.elem_, 0, size_);
	return *this;
}
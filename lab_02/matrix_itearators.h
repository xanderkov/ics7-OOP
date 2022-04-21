#pragma once
#include "matrix.h"

template <typename T>
Iterator<T> Matrix<T>::begin()
{
	return Iterator<T>(*this, 0);
}

template <typename T>
Iterator<T> Matrix<T>::end()
{
	return Iterator<T>(*this, _cols * _rows);
}

template <typename T>
ConstIterator<T> Matrix<T>::begin() const
{

}
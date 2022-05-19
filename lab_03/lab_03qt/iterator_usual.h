#ifndef ITERATOR_USUAL_H
#define ITERATOR_USUAL_H

#include "iterator_base.h"

template <class T>
class VectorBase;
template <class T>
class MatrixBase;

template <class T>
class Iterator : public IteratorBase<T>
{
public:
    Iterator(const Iterator &other);

    T &operator*();
    T *operator->();

    friend class VectorBase<T>;
    friend class MatrixBase<T>;

private:
    Iterator(T *pointer);
};

template <class T>
Iterator<T>::Iterator(T *pointer) : IteratorBase<T>(pointer){}

template <class T>
Iterator<T>::Iterator(const Iterator &other) : IteratorBase<T>(other.pointer){}

template <class T>
T &Iterator<T>::operator*()
{
    return *this->pointer;
}

template <class T>
T *Iterator<T>::operator->()
{
    return this->pointer;
}

#endif // ITERATOR_USUAL_H

#ifndef ITERATOR_BASE_H
#define ITERATOR_BASE_H

#include <cstddef>

template <class T>
class IteratorBase
{
public:
    IteratorBase(const IteratorBase &other);
    IteratorBase &operator=(const IteratorBase &other);
    virtual ~IteratorBase();

    IteratorBase &operator++();
    IteratorBase operator++(int); //постфикс
    IteratorBase &operator--();
    IteratorBase operator--(int);

    ptrdiff_t operator-(const IteratorBase &other); //разница указателей

    bool operator==(const IteratorBase &other);
    bool operator!=(const IteratorBase &other);

protected:
    IteratorBase(T *pointer);
    T *pointer;
};

template <class T>
IteratorBase<T>::IteratorBase(T *pointer)
{
    this->pointer = pointer;
}

template <class T>
IteratorBase<T>::IteratorBase(const IteratorBase &other)
{
    this->pointer = other.pointer;
}

template <class T>
IteratorBase<T>::~IteratorBase()
{
    this->pointer = nullptr;
}

template <class T>
IteratorBase<T> &IteratorBase<T>::operator=(const IteratorBase &other)
{
    if (this != &other)
    {
        this->pointer = other.pointer;
    }

    return *this;
}

template <class T>
IteratorBase<T> &IteratorBase<T>::operator++()
{
    ++this->pointer;
    return *this;
}

template <class T>
IteratorBase<T> IteratorBase<T>::operator++(int)
{
    IteratorBase temp(*this);
    this->operator++();
    return temp;
}

template <class T>
IteratorBase<T> &IteratorBase<T>::operator--()
{
    --this->pointer;
    return *this;
}

template <class T>
IteratorBase<T> IteratorBase<T>::operator--(int)
{
    IteratorBase temp(*this);
    this->operator--();
    return temp;
}

template <class T>
ptrdiff_t IteratorBase<T>::operator-(const IteratorBase<T> &other)
{
    return this->pointer - other.pointer;
}

template <class T>
bool IteratorBase<T>::operator==(const IteratorBase &other)
{
    return this->pointer == other.pointer;
}

template <class T>
bool IteratorBase<T>::operator!=(const IteratorBase &other)
{
    return this->pointer != other.pointer;
}

#endif // ITERATOR_BASE_H

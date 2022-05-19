#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <cstddef>
#include <ctime>
#include <iostream>

#include "iterator_const.h"
#include "iterator_usual.h"
#include "error_container.h"

template <class T>
class MatrixBase
{
private:
    // для строки
    // предоставляет замену другого объекта для контроля доступа к нему
    class Proxy
    {
    public:
        Proxy(size_t m, T *data);

        T &at(size_t index);
        const T &at(size_t index) const;
        T &operator[](size_t index);
        const T &operator[](size_t index) const;

    private:
        size_t m;
        T *data;
    };

public:
    MatrixBase(size_t n, size_t m);
    MatrixBase(size_t n, size_t m, const T &data);
    MatrixBase(size_t n, size_t m, Iterator<T> first, Iterator<T> last);
    MatrixBase(size_t n, size_t m, ConstIterator<T> first, ConstIterator<T> last);
    MatrixBase(size_t n, size_t m, std::initializer_list<T> list);
    MatrixBase(const MatrixBase &other);
    MatrixBase(MatrixBase &&other);
    virtual ~MatrixBase();
    MatrixBase &operator=(const MatrixBase &other);
    MatrixBase &operator=(MatrixBase &&other);
    MatrixBase &operator=(std::initializer_list<T> lst);

    Proxy at(size_t index);
    const Proxy at(size_t) const;
    Proxy operator[](size_t index);
    const Proxy operator[](size_t index) const;

    Iterator<T> begin();
    ConstIterator<T> cbegin() const;
    Iterator<T> end();
    ConstIterator<T> cend() const;

    Iterator<T> rbegin();
    ConstIterator<T> rcbegin() const;
    Iterator<T> rend();
    ConstIterator<T> rcend() const;

    size_t getN() const;
    size_t getM() const;
    size_t getCapacity() const;
    void zero();
    void swap(MatrixBase &other);



    template <class U>
    friend inline void swap(MatrixBase<U> &first, MatrixBase<U> &second);
    template <class U>
    friend inline bool operator==(const MatrixBase<U> &first, const MatrixBase<U> &second);
    template <class U>
    friend inline bool operator!=(const MatrixBase<U> &first, const MatrixBase<U> &second);
    template <class U>
    friend inline bool operator<(const MatrixBase<U> &first, const MatrixBase<U> &second);
    template <class U>
    friend inline bool operator<=(const MatrixBase<U> &first, const MatrixBase<U> &second);
    template <class U>
    friend inline bool operator>(const MatrixBase<U> &first, const MatrixBase<U> &second);
    template <class U>
    friend inline bool operator>=(const MatrixBase<U> &first, const MatrixBase<U> &second);

    template <class U>
    friend inline std::ostream &operator<<(std::ostream &, const MatrixBase<U> &);
    virtual bool IsMove() = 0;

protected:
    size_t n;
    size_t m;
    size_t memory_dump;
    T *_data;
};

template <class T>
MatrixBase<T>::Proxy::Proxy(size_t m, T *data) : m(m), data(data)
{
}

template <class T>
T &MatrixBase<T>::Proxy::at(size_t index)
{
    if (index < this->m)
    {
        return *(this->data + index);
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
const T &MatrixBase<T>::Proxy::at(size_t index) const
{
    if (index < this->m)
    {
        return *(this->data + index);
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
T &MatrixBase<T>::Proxy::operator[](size_t index)
{
    if (index < this->m)
    {
        return *(this->data + index);
    }
    else
    {
        time_t t_time = time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
const T &MatrixBase<T>::Proxy::operator[](size_t index) const
{
    if (index < this->m)
    {
        return *(this->data + index);
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
MatrixBase<T>::MatrixBase(size_t n, size_t m)
    : n(n), m(m), memory_dump(n * m)
{
    try
    {
        this->_data = new T[this->memory_dump];
    }
    catch (std::bad_alloc &ex)
    {
        time_t t_time = time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
MatrixBase<T>::MatrixBase(size_t n, size_t m, const T &data)
    : MatrixBase(n, m)
{
    for (size_t i = 0; i < this->memory_dump; ++i)
    {
        this->_data[i] = data;
    }
}

template <class T>
MatrixBase<T>::MatrixBase(size_t n, size_t m, Iterator<T> first, Iterator<T> last)
    : MatrixBase(n, m)
{
    size_t size = this->memory_dump <= static_cast<size_t>(last - first) ? this->memory_dump : static_cast<size_t>(last - first);

    for (size_t i = 0; i < size; ++i, ++first)
    {
        this->_data[i] = *first;
    }

    for (size_t i = size; i < this->memory_dump; ++i)
    {
        this->_data[i] = 0;
    }
}

template <class T>
MatrixBase<T>::MatrixBase(size_t n, size_t m, ConstIterator<T> first, ConstIterator<T> last)
    : MatrixBase(n, m)
{
    size_t size = this->memory_dump <= static_cast<size_t>(last - first) ? this->memory_dump : static_cast<size_t>(last - first);

    for (size_t i = 0; i < size; ++i, ++first)
    {
        this->_data[i] = *first;
    }

    for (size_t i = size; i < this->memory_dump; ++i)
    {
        this->_data[i] = 0;
    }
}

template <class T>
MatrixBase<T>::MatrixBase(size_t n, size_t m, std::initializer_list<T> list)
    : MatrixBase(n, m)
{
    size_t size = this->memory_dump <= list.size() ? this->memory_dump : list.size();
    typename std::initializer_list<T>::Iterator<T> iter = list.begin();

    for (size_t i = 0; i < size; ++i, ++iter)
    {
        this->_data[i] = *iter;
    }

    for (size_t i = size; i < this->memory_dump; ++i)
    {
        this->_data[i] = 0;
    }
}

template <class T>
MatrixBase<T>::MatrixBase(const MatrixBase &other)
    : MatrixBase(other.n, other.m)
{
    std::copy(other._data, other._data + other.memory_dump, this->_data);
}

template <class T>
MatrixBase<T>::MatrixBase(MatrixBase &&other)
    : n(other.n), m(other.m), _data(other._data)
{
    other.n = 0;
    other.m = 0;
    other.memory_dump = 0;
    other._data = nullptr;
}

template <class T>
MatrixBase<T>::~MatrixBase()
{
    delete[] _data;
    this->n = 0;
    this->m = 0;
    this->memory_dump = 0;
    this->_data = nullptr;
}

template <class T>
MatrixBase<T> &MatrixBase<T>::operator=(const MatrixBase<T> &other)
{
    if (this != &other)
    {
        this->n = other.n;
        this->m = other.m;
        this->memory_dump = other.memory_dump;

        try
        {
            delete[] this->_data;
            this->_data = new T[this->memory_dump];
        }
        catch (std::bad_alloc &ex)
        {
            time_t t_time(NULL);
            throw MemError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
        }

        std::copy(other._data, other._data + other.memory_dump, this->_data);
    }

    return *this;
}

template <class T>
MatrixBase<T> &MatrixBase<T>::operator=(MatrixBase &&other)
{
    if (this != &other)
    {
        this->n = other.n;
        this->m = other.m;
        this->memory_dump = other.memory_dump;

        delete[] this->_data;
        this->_data = other._data;

        other.n = 0;
        other.m = 0;
        other.memory_dump = 0;
        other._data = nullptr;
    }

    return *this;
}

template <class T>
MatrixBase<T> &MatrixBase<T>::operator=(std::initializer_list<T> lst)
{
    size_t size = this->memory_dump <= lst.size() ? this->memory_dump : lst.size();
    typename std::initializer_list<T>::ConstIterator<T> iter = lst.begin();

    for (size_t i = 0; i < size; ++i, ++iter)
    {
        this->_data[i] = *iter;
    }

    for (size_t i = size; i < this->memory_dump; ++i)
    {
        this->_data[i] = 0;
    }

    return *this;
}

template <class T>
typename MatrixBase<T>::Proxy MatrixBase<T>::at(size_t index)
{
    if (index < this->n)
    {
        return Proxy(this->m, this->_data + this->m * index);
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
const typename MatrixBase<T>::Proxy MatrixBase<T>::at(size_t index) const
{
    if (index < this->n)
    {
        return Proxy(this->m, this->_data + this->m * index);
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
typename MatrixBase<T>::Proxy MatrixBase<T>::operator[](size_t index)
{
    if (index < this->n)
    {
        return Proxy(this->m, this->_data + this->m * index);
    }
    else
    {
        time_t t_time = time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
const typename MatrixBase<T>::Proxy MatrixBase<T>::operator[](size_t index) const
{
    if (index < this->n)
    {
        return Proxy(this->m, this->_data + this->m * index);
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
}

template <class T>
Iterator<T> MatrixBase<T>::begin()
{
    return Iterator<T>(this->_data);
}

template <class T>
ConstIterator<T> MatrixBase<T>::cbegin() const
{
    return ConstIterator<T>(this->_data);
}

template <class T>
Iterator<T> MatrixBase<T>::end()
{
    return Iterator<T>(this->_data + this->memory_dump);
}

template <class T>
ConstIterator<T> MatrixBase<T>::cend() const
{
    return ConstIterator<T>(this->_data + this->memory_dump);
}

template <class T>
Iterator<T> MatrixBase<T>::rbegin()
{
    return Iterator<T>(this->_data + this->memory_dump - 1);
}

template <class T>
ConstIterator<T> MatrixBase<T>::rcbegin() const
{
    return ConstIterator<T>(this->_data + this->memory_dump - 1);
}

template <class T>
Iterator<T> MatrixBase<T>::rend()
{
    return Iterator<T>(this->_data - 1);
}

template <class T>
ConstIterator<T> MatrixBase<T>::rcend() const
{
    return ConstIterator<T>(this->_data - 1);
}

template <class T>
size_t MatrixBase<T>::getN() const
{
    return this->n;
}

template <class T>
size_t MatrixBase<T>::getM() const
{
    return this->m;
}

template <class T>
size_t MatrixBase<T>::getCapacity() const
{
    return this->memory_dump;
}

template <class T>
void MatrixBase<T>::zero()
{
    for (size_t i = 0; i < this->memory_dump; ++i)
    {
        this->_data[i] = T();
    }
}

template <class T>
void MatrixBase<T>::swap(MatrixBase<T> &other)
{
    std::swap(this->n, other.n);
    std::swap(this->m, other.m);
    std::swap(this->memory_dump, other.memory_dump);
    std::swap(this->_data, other._data);
}

template <class T>
void swap(MatrixBase<T> &first, MatrixBase<T> &second)
{
    first.swap(second);
}

template <class T>
bool operator==(const MatrixBase<T> &first, const MatrixBase<T> &second)
{
    bool are_equal = first.getCapacity() == second.getCapacity();

    if (are_equal)
    {
        for (size_t i = 0; i < first.size() && are_equal; ++i)
        {
            if (first[i] != second[i])
            {
                are_equal = false;
            }
        }
    }

    return are_equal;
}

template <class T>
bool operator!=(const MatrixBase<T> &first, const MatrixBase<T> &second)
{
    return !(second == first);
}

template <class T>
bool operator<(const MatrixBase<T> &first, const MatrixBase<T> &second)
{
    bool is_less = first.getCapacity() < second.getCapacity();

    if (!is_less && first.getCapacity() == second.getCapacity())
    {
        for (size_t i = 0; i < first.getCapacity() && !is_less; ++i)
        {
            if (first[i] < second[i])
            {
                is_less = true;
            }
        }
    }

    return is_less;
}

template <class T>
bool operator<=(const MatrixBase<T> &first, const MatrixBase<T> &second)
{
    return first < second || first == second;
}

template <class T>
bool operator>(const MatrixBase<T> &first, const MatrixBase<T> &second)
{
    return !(first < second) && !(first == second);
}

template <class T>
bool operator>=(const MatrixBase<T> &first, const MatrixBase<T> &second)
{
    return first > second || first == second;
}

template <class T>
std::ostream &operator<<(std::ostream &stream, const MatrixBase<T> &mtx)
{
    for (size_t i = 0; i < mtx.getN(); ++i)
    {
        for (size_t j = 0; j < mtx.getM(); ++j)
        {
            stream << mtx[i][j] << " ";
        }

        stream << std::endl;
    }

    return stream;
}

#endif // MATRIX_BASE_H

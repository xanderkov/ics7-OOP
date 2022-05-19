#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <istream>
#include <iterator>
#include <memory>
#include <ostream>

#include "vector_base.h"
#include "error_container.h"

template <typename T>
class Vector : public BaseVector<T>
{
private:
    template <typename Ptr, typename Ref, typename VectorPtr>
    class Iterator;
public:
    using iterator = Iterator<std::shared_ptr<T>, T &, Vector<T> *>;
    using const_iterator = Iterator<const std::shared_ptr<T>, const T &, const Vector<T> *>;

    Vector();
    Vector(size_t len, const T &data);
    Vector(Vector<T> &&other) noexcept;
    Vector(const std::initializer_list<T> &list);
    Vector(const Vector<T> &other);
    Vector<T> &operator=(const Vector<T> &other);
    Vector<T> &operator=(Vector<T> &&other);

    iterator begin();
    iterator end();
    const const_iterator cbegin() const;
    const const_iterator cend() const;
    const const_iterator begin() const;
    const const_iterator end() const;

    void clean() override; // полная отчистка
    size_t getLen() const override;
    void push_back(const T &data);
    void erase(iterator &iter); // стирание одного

    T &operator[](int index);
    const T &operator[](int index) const;
    T &at(size_t index);
    const T &at(size_t index) const;

private:
    const size_t START_LEN = 8;
    void resize(); // увеличение размера в 2 раза
    void allocate(size_t len);
    size_t allocated_len;
    T *data_;
};

// конструкторы
template <typename T>
Vector<T>::Vector()
{
    allocate(START_LEN);
}

template <typename T>
Vector<T>::Vector(size_t len, const T &data)
{
    allocate(len);
    for (int i = 0; i < len; ++i)
        push_back(data);
}

template <typename T>
Vector<T>::Vector(Vector<T> &&other) noexcept
{
    data_ = other.data_;
    allocated_len = other.allocated_len;
    this->len_ = other.len_;
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &list)
{
    allocate(list.size());
    this->len_ = 0;
    data_ = nullptr;
    for (auto &element : list)
    {
        this->push_back(element);
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other)
{
    data_ = other.data_;
    allocated_len = other.allocated_len;
    this->len_ = other.len_;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    data_ = other.data_;
    this->len_ = other.len_;
    allocated_len = other.allocated_len;

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other)
{
    data_ = other.data_;
    this->len_ = other.len_;
    allocated_len = other.allocated_len;
    other.~Vector();

    return *this;
}

template <typename T>
void Vector<T>::allocate(size_t len)
{
    time_t t_time = time(NULL);
    data_ = new T[len];
    if (!data_)
        throw MemError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    allocated_len = len;
}


template <typename T>
void Vector<T>::clean()
{
    if (!data_)
        return;
    delete[] data_;
    data_ = nullptr;
    this->len_ = 0;
    allocated_len = 0;
}

template <typename T>
void Vector<T>::resize()
{
    size_t new_len = allocated_len * 2;
    T *new_data = new T[new_len];
    for (size_t i = 0; i < this->len_; ++i)
        new_data[i] = data_[i];

    delete[] data_;
    data_ = new_data;
    allocated_len = new_len;
}

template <typename T>
void Vector<T>::erase(iterator &iter)
{
    time_t t_time = time(NULL);
    if (iter > end())
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    for (auto i = iter; i != end() - 1; ++i)
        *i = *(i + 1);
    this->len_--;
}

template <typename T>
size_t Vector<T>::getLen() const
{
    return this->len_;
}

template <typename T>
void Vector<T>::push_back(const T &data)
{
    if (!data_)
        allocate(START_LEN);
    if (this->len_ == allocated_len)
        resize();
    data_[this->len_++] = data;
}

template <typename T>
T &Vector<T>::operator[](int index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->len_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return data_[index];
}

template <typename T>
const T &Vector<T>::operator[](int index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->len_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return data_[index];
}

template <typename T>
T &Vector<T>::at(size_t index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->len_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return data_[index];
}

template <typename T>
const T &Vector<T>::at(size_t index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->len_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return data_[index];
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return iterator(this, 0);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return iterator(this, getLen());
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return const_iterator(this, 0);
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return const_iterator(this, getLen());
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return cbegin();
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::end() const
{
    return cend();
}

#endif // VECTOR_H

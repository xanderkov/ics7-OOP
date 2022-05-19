#ifndef MATRIX_H
#define MATRIX_H

#include "matrix_base.h"

template <class T>
class Matrix : public MatrixBase<T>
{
public:
    explicit Matrix(size_t n, size_t m);
    explicit Matrix(size_t n, size_t m, const T &data);
    Matrix(size_t n, size_t m, Iterator<T>  first, Iterator<T>  last);
    Matrix(size_t n, size_t m, ConstIterator<T> first, ConstIterator<T> last);
    Matrix(size_t n, size_t m, std::initializer_list<T> list);
    Matrix(const Matrix &other);
    Matrix(Matrix &&other);
    virtual ~Matrix() = default;
    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other);
    Matrix &operator=(std::initializer_list<T> list);

    template <class U>
    friend Matrix<U> operator+(const Matrix<U> &first, const Matrix<U> &second);
    template <class U>
    friend Matrix<U> operator+(const Matrix<U> &mtx, const U &data);
    Matrix &operator+=(const Matrix &other);
    Matrix &operator+=(const T &data);
    template <class U>
    friend Matrix<U> operator-(const Matrix<U> &first, const Matrix<U> &second);
    template <class U>
    friend Matrix<U> operator-(const Matrix<U> &mtx, const U &data);
    Matrix &operator-=(const Matrix &other);
    Matrix &operator-=(const T &data);
    template <class U>
    friend Matrix<U> operator*(const Matrix<U> &first, const Matrix<U> &second);
    template <class U>
    friend Matrix<U> operator*(const Matrix<U> &mtx, const U &data);
    Matrix &operator*=(const Matrix &other);
    Matrix &operator*=(const T &data);
    template <class U>
    friend Matrix<U> operator/(const Matrix<U> &mtx, const U &data);
    Matrix &operator/=(const T &data);
};

template <class T>
Matrix<T>::Matrix(size_t n, size_t m)
    : MatrixBase<T>(n, m)
{
}

template <class T>
Matrix<T>::Matrix(size_t n, size_t m, const T &data)
    : MatrixBase<T>(n, m, data)
{
}

template <class T>
Matrix<T>::Matrix(size_t n, size_t m, Iterator<T> first, Iterator<T> last)
    : MatrixBase<T>(n, m, first, last)
{
}

template <class T>
Matrix<T>::Matrix(size_t n, size_t m, ConstIterator<T> first, ConstIterator<T> last)
    : MatrixBase<T>(n, m, first, last)
{
}

template <class T>
Matrix<T>::Matrix(size_t n, size_t m, std::initializer_list<T> list)
    : MatrixBase<T>(n, m, list)
{
}

template <class T>
Matrix<T>::Matrix(const Matrix &other)
    : MatrixBase<T>(other)
{
}

template <class T>
Matrix<T>::Matrix(Matrix &&other)
    : MatrixBase<T>(std::move(other))
{
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &second)
{
    MatrixBase<T>::operator=(second);

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&second)
{
    MatrixBase<T>::operator=(std::move(second));

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(std::initializer_list<T> list)
{
    MatrixBase<T>::operator=(list);

    return *this;
}

template <class T>
Matrix<T> operator+(const Matrix<T> &first, const Matrix<T> &second)
{
    Matrix<T> result = first;
    size_t rows_count = first.getN() < second.getN() ? first.getN() : second.getN();
    size_t cols_count = first.getM() < second.getM() ? first.getM() : second.getM();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            result[i][j] += second[i][j];
        }
    }

    return result;
}

template <class T>
Matrix<T> operator+(const Matrix<T> &mtx, const T &data)
{
    Matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.getCapacity(); ++i)
    {
        result._data[i] += data;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &second)
{
    size_t rows_count = this->getN() < second.getN() ? this->getN() : second.getN();
    size_t cols_count = this->getM() < second.getM() ? this->getM() : second.getM();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] += second[i][j];
        }
    }

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator+=(const T &data)
{
    for (size_t i = 0; i < this->getCapacity(); ++i)
    {
        this->_data[i] += data;
    }

    return *this;
}

template <class T>
Matrix<T> operator-(const Matrix<T> &first, const Matrix<T> &second)
{
    Matrix<T> result = first;
    size_t rows_count = first.getN() < second.getN() ? first.getN() : second.getN();
    size_t cols_count = first.getM() < second.getM() ? first.getM() : second.getM();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            result[i][j] -= second[i][j];
        }
    }

    return result;
}

template <class T>
Matrix<T> operator-(const Matrix<T> &mtx, const T &data)
{
    Matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.getCapacity(); ++i)
    {
        result._data[i] -= data;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &second)
{
    size_t rows_count = this->getN() < second.getN() ? this->getN() : second.getN();
    size_t cols_count = this->getM() < second.getM() ? this->getM() : second.getM();

    for (size_t i = 0; i < rows_count; ++i)
    {
        for (size_t j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] -= second[i][j];
        }
    }

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator-=(const T &data)
{
    for (size_t i = 0; i < this->getCapacity(); ++i)
    {
        this->_data[i] -= data;
    }

    return *this;
}

template <class T>
Matrix<T> operator*(const Matrix<T> &first, const Matrix<T> &second)
{
    if (first.getM() == second.getN())
    {
        Matrix<T> result = first;

        for (size_t i = 0; i < first.getN(); ++i)
        {
            for (size_t j = 0; j < second.getM(); ++j)
            {
                for (size_t k = 0; k < first.getM(); ++k)
                {
                    result[i][j] += first[i][k] * second[k][j];
                }
            }
        }

        return result;
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, "Matrix<T>::operator*", __LINE__, ctime(&t_time));
    }
}

template <class T>
Matrix<T> &operator*(const Matrix<T> &mtx, const T &data)
{
    Matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.getCapacity(); ++i)
    {
        result._data[i] *= data;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &other)
{
    if (this->getM() == other.getN())
    {
        for (size_t i = 0; i < this->getN(); ++i)
        {
            for (size_t j = 0; j < other.getM(); ++j)
            {
                for (size_t k = 0; k < this->getM(); ++k)
                {
                    (*this)[i][j] = (*this)[i][k] * other[k][j];
                }
            }
        }

        return *this;
    }
    else
    {
        time_t t_time(NULL);
        throw RangeError(__FILE__, typeid((*this).name(), __LINE__, ctime(&t_time)));
    }
}

template <class T>
Matrix<T> &Matrix<T>::operator*=(const T &data)
{
    for (size_t i = 0; i < this->getCapacity(); ++i)
    {
        this->_data[i] *= data;
    }

    return *this;
}

template <class T>
Matrix<T> &operator/(const Matrix<T> &mtx, const T &data)
{
    Matrix<T> result = mtx;

    for (size_t i = 0; i < mtx.getCapacity(); ++i)
    {
        result._data[i] /= data;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator/=(const T &data)
{
    for (size_t i = 0; i < this->getCapacity(); ++i)
    {
        this->_data[i] /= data;
    }

    return *this;
}

#endif // MATRIX_H

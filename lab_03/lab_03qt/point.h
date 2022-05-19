#ifndef POINT_H
#define POINT_H

#include <istream>
#include <memory>

#include "vector.h"
#include "matrix.h"

template <typename T>
class Point
{
public:
    explicit Point();
    explicit Point(const T &x, const T &y, const T &z);
    Point(const Point &other);
    Point &operator=(const Point &other);

    void setX(T x);
    void setY(T y);
    void setZ(T z);

    T getX() const;
    T getY() const;
    T getZ() const;

    void Transform(const std::shared_ptr<Matrix<T>> mtr);

    Point &operator+=(const Point &other);
    Point operator+(const Point &other);
    Point &operator+=(const T &data);
    Point &operator-=(const Point &other);
    Point &operator-=(const T &data);
    Point &operator*=(const Point &other);
    Point &operator*=(const T &data);
    Point &operator/=(const Point &other);
    Point &operator/=(const T &data);

private:
    T x_;
    T y_;
    T z_;
};

// ввод
template <typename T>
std::istream &operator>>(std::istream &in, Point<T> &point)
{
    T x, y, z;
    in >> x >> y >> z;
    point.setX(x);
    point.setY(y);
    point.setZ(z);

    return in;
}

// конструкторы
template <typename T>
Point<T>::Point() : x_(0), y_(0), z_(0) {}

template <typename T>
Point<T>::Point(const T &x, const T &y, const T &z)
    : x_(x), y_(y), z_(z) {}

template <typename T>
Point<T>::Point(const Point<T> &other)
    : Point(other.x_, other.y_, other.z_) {}

template <typename T>
Point<T> &Point<T>::operator=(const Point<T> &other)
{
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;

    return *this;
}

// установка координат
template <typename T>
void Point<T>::setX(T x)
{
    x_ = x;
}

template <typename T>
void Point<T>::setY(T y)
{
    y_ = y;
}

template <typename T>
void Point<T>::setZ(T z)
{
    z_ = z;
}

// получение координат
template <typename T>
T Point<T>::getX() const
{
    return x_;
}

template <typename T>
T Point<T>::getY() const
{
    return y_;
}

template <typename T>
T Point<T>::getZ() const
{
    return z_;
}

// преобразование
template <typename T>
void Point<T>::Transform(const std::shared_ptr<Matrix<T>> mtr)
{
    Vector<T> result(4, 0);
    Vector<T> data = {x_, y_, z_, 1.0};
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            result[i] += data[j] * (*mtr)[i][j];
        }
    }

    this->setX(result[0]);
    this->setY(result[1]);
    this->setZ(result[2]);
}

// перегрузка арифметических операторов
template <typename T>
Point<T> &Point<T>::operator+=(const Point<T> &other)
{
    x_ += other.x_;
    y_ += other.y_;
    z_ += other.z_;

    return *this;
}

template <typename T>
Point<T> Point<T>::operator+(const Point<T> &other)
{
    Point<T> sum = Point(x_ + other.x_, y_ + other.y_, z_ + other.z_);
    return sum;
}

template <typename T>
Point<T> &Point<T>::operator+=(const T &data)
{
    x_ += data;
    y_ += data;
    z_ += data;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator-=(const Point<T> &other)
{
    x_ -= other.x_;
    y_ -= other.y_;
    z_ -= other.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator-=(const T &data)
{
    x_ -= data;
    y_ -= data;
    z_ -= data;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator*=(const Point<T> &other)
{
    x_ *= other.x_;
    y_ *= other.y_;
    z_ *= other.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator*=(const T &data)
{
    x_ *= data;
    y_ *= data;
    z_ *= data;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator/=(const Point<T> &other)
{
    x_ /= other.x_;
    y_ /= other.y_;
    z_ /= other.z_;

    return *this;
}

template <typename T>
Point<T> &Point<T>::operator/=(const T &data)
{
    x_ /= data;
    y_ /= data;
    z_ /= data;

    return *this;
}

#endif // POINT_H

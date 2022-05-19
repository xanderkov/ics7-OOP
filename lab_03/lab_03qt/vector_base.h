#ifndef VECTOR_BASE_H
#define VECTOR_BASE_H

#include <ctime>

template <typename T>
class BaseVector
{
public:
    BaseVector() = default;
    ~BaseVector() = default;

    virtual void clean() = 0;
    virtual size_t getLen() const = 0;

protected:
    size_t len_ = 0;
};

#endif // VECTOR_BASE_H

#pragma once
#include <cstddef>

class BaseMatrix {
public:
    BaseMatrix(size_t rows = 0, size_t columns = 0): _rows(rows), _cols(columns) {}

    virtual size_t GetColumns() const noexcept { return _cols; };
    virtual size_t GetRows() const noexcept { return _rows; };
    virtual operator bool() const noexcept { return _cols && _rows; }

    virtual ~BaseMatrix() = 0;

protected:
    size_t _rows = 0, _cols = 0;
};

BaseMatrix::~BaseMatrix() {}

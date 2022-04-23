#pragma once
#include <iostream>
#include <iterator>
#include <memory>
#include "matrix_base.hpp"
#include "exception.hpp"
#include "const_iterator.hpp"
#include "iterator.hpp"

template <typename Type>
using SharedPtr = std::shared_ptr<Type>;
using string = std::string;

template <typename Type>
class Matrix: public BaseMatrix 
{
public:
    class MatrixRow;
    friend Iterator<Type>;
    friend ConstIterator<Type>;

public:
    explicit Matrix(size_t rows = 0, size_t columns = 0);
    Matrix(size_t rows, size_t columns, const Type &filler);
    
    Matrix(size_t rows, size_t columns, Type **matrix);
    Matrix(std::initializer_list<std::initializer_list<Type> > init_list);
    explicit Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix);

    virtual ~Matrix() = default;

    Matrix<Type> &operator=(const Matrix &matrix);
    Matrix<Type> &operator=(Matrix &&matrix);
    Matrix<Type> &operator=(std::initializer_list<std::initializer_list<Type> > init_list);

    template <typename Type2>
    decltype(auto) operator+(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) operator+(const Type2 &elem) const noexcept;
    Matrix<Type> &operator+=(const Type &elem) noexcept;
    Matrix<Type> &operator+=(const Matrix &matrix);

    template <typename Type2>
    decltype(auto) addMatrix(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) addElem(const Type2 &elem) const noexcept;
    Matrix<Type> &addEqElem(const Type &elem) noexcept;
    Matrix<Type> &addEqMatrix(const Matrix &matrix);
    

    template <typename Type2>
    decltype(auto) operator-(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) operator-(const Type2 &elem) const noexcept;
    Matrix<Type> &operator-=(const Matrix &matrix);
    Matrix<Type> &operator-=(const Type &elem) noexcept;

    template <typename Type2>
    decltype(auto) subMatrix(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) subElem(const Type2 &elem) const noexcept;
    Matrix<Type> &subEqMatrix(const Matrix &matrix);
    Matrix<Type> &subEqElem(const Type &elem) noexcept;


    template <typename Type2>
    decltype(auto) operator*(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) operator*(const Type2 &elem) const noexcept;
    Matrix<Type> &operator*=(const Matrix &matrix);
    Matrix<Type> &operator*=(const Type &elem) noexcept;

    template <typename Type2>
    decltype(auto) mulMatrix(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) mulElem(const Type2 &elem) const noexcept;
    Matrix<Type> &mulEqMatrix(const Matrix &matrix);
    Matrix<Type> &mulEqElem(const Type &elem) noexcept;


    template <typename Type2>
    decltype(auto) operator/(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) operator/(const Type2 &elem) const;
    Matrix<Type> &operator/=(const Matrix &matrix);
    Matrix<Type> &operator/=(const Type &elem);

    template <typename Type2>
    decltype(auto) divMatrix(const Matrix<Type2> &matrix) const;
    template <typename Type2>
    decltype(auto) divElem(const Type2 &elem) const;
    Matrix<Type> &divEqMatrix(const Matrix &matrix);
    Matrix<Type> &divEqElem(const Type &elem);

    //-Matrix
    Matrix<Type> operator-();
    Matrix<Type> neg();

    bool isSquare() const;
    Type determinant() const;
    void transpose();
    // -1 степень
    void inverse();

    ConstIterator<Type> begin() const;
    ConstIterator<Type> end() const;
    Iterator<Type> begin();
    Iterator<Type> end();
    ConstIterator<Type> cbegin() const;
    ConstIterator<Type> cend() const;

    
    void fill(Iterator<Type> start, const Iterator<Type> &end, const Type &value);
    void fill(Iterator<Type> start, Iterator<Type> source_start, const Iterator<Type> &source_end);
    void fill(Iterator<Type> start, ConstIterator<Type> source_start, const ConstIterator<Type> &source_end);
    void reverseSeq(Iterator<Type> start, Iterator<Type> end);

    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;

    MatrixRow operator[](size_t row);
    const MatrixRow operator[](size_t row) const;
    Type &at(size_t row, size_t col);
    const Type &at(size_t row, size_t col) const;
    Type &operator()(size_t row, size_t col);
    const Type &operator()(size_t row, size_t col) const;


private:
    SharedPtr<MatrixRow[]> _data { nullptr };
    SharedPtr<MatrixRow[]> _allocateMemory(size_t rows, size_t cols);
    void _moveRow(size_t from, size_t to);
    void _moveCol(size_t from, size_t to);
    void _checkIndex(size_t pos, size_t limit) const;
    void _checkSizes(const Matrix &matrix) const;
    void _checkMultSizes(const Matrix &matrix) const;

public:
    // подкласс матрицы строки
    class MatrixRow 
    {
        friend Iterator<Type>;
        friend ConstIterator<Type>;
    private:
        SharedPtr<Type[]> _data = nullptr;
        size_t _size = 0;
    public:
        MatrixRow(Type *data, const size_t size): _data(data), _size(size) {}
        MatrixRow(): _data(nullptr), _size(0) {}
        Type &operator[](size_t index);
        const Type &operator[](size_t index) const;
        void reset(Type *data, const size_t size);
        void reset();
        
    private:
        Type *getAddr() { return _data.get(); }
        const Type *getAddr() const { return _data.get(); }
    
    };

};

#include "../implementation/matrix_constructors_and_eqoperators.hpp"
#include "../implementation/matrix_iterators.hpp"
#include "../implementation/matrix_math.hpp"
#include "../implementation/matrix_oper_methods.hpp"
#include "../implementation/matrix_operators.hpp"
#include "../implementation/matrix_private.hpp"
#include "../implementation/matrix_rest_methods.hpp"
#include "../implementation/matrix_row.hpp"

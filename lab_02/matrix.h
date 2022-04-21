#pragma once
#include <iostream>
#include <iterator>
#include <memory>

template <typename Type>
using SharedPtr = std::shared_ptr<Type>;
using string = std::string;

template <typename Type>
class Matrix : public BaseMatrix
{
public:
	class MatrixRow;
	friend Iterator<Type>;
	friend ConstIterator<Type>;

public:
	explicit Matrix(size_t rows = 0, size_t columns = 0);
	Matrix(size_t rows, size_t columns, const Type& filter);
	Matrix(size_t rows, size_t columns, Type** matrix); // c matrix
	Matrix(std::initializer_list<std::initializer_list<Type> > init_list);
	explicit Matrix(const Matrix& matrix);
	Matrix(Matrix&& matrix);

	virtual ~Matrix() = default;

	Matrix<Type>& operator=(const Matrix& matrix);
	Matrix<Type>& operator=(Matrix&& matrix);

	Matrix<Type>& operator=(strd::initilizer_list<std::initilizer_list<Type> > init_list);

	Matrix<Type> operator+(const Matrix& matrix) const;
	Matrix<Type> operator-(const Matrix& matrix) const;
	Matrix<Type> operator*(const Matrix& matrix) const;
	Matrix<Type> operator/(const Matrix& matrix) const;
	
	Matrix<Type> addMatrix(const Matrix& matrix) const;
	Matrix<Type> subMatrix(const Matrix& matrix) const;
	Matrix<Type> mulMatrix(const Matrix& matrix) const;
	Matrix<Type> divMatrix(const Matrix& matrix) const;

	Matrix<Type> operator+(const Type& elem) const noexcept;
	Matrix<Type> operator-(const Type& elem) const noexcept;
	Matrix<Type> operator*(const Type& elem) const noexcept;
	Matrix<Type> operator/(const Type& elem) const;

	Matrix<Type> addElem(const Type& elem) const noexcept;
	Matrix<Type> subElem(const Type& elem) const noexcept;
	Matrix<Type> mulElem(const Type& elem) const noexcept;
	Matrix<Type> divElem(const Type& elem) const;


	Matrix<Type> operator-();
	Matrix<Type> neg();

	Matrix<Type>& operator+=(const Matrix& matrix);
	Matrix<Type>& operator-=(const Matrix& matrix);
	Matrix<Type>& operator*=(const Matrix& matrix);
	Matrix<Type>& operator/=(const Matrix& matrix);

	Matrix<Type>& addEqMatrix(const Matrix& matrix);
	Matrix<Type>& subEqMatrix(const Matrix& matrix);
	Matrix<Type>& mulEqMatrix(const Matrix& matrix);
	Matrix<Type>& divEqMatrix(const Matrix& matrix);

	Matrix<Type>& operator+=(const Type& elem) noexcept;
	Matrix<Type>& operator-=(const Type& elem) noexcept;
	Matrix<Type>& operator*=(const Type& elem) noexcept;
	Matrix<Type>& operator/=(const Type& elem);

	Matrix<Type>& addEqElem(const Type& elem) noexcept;
	Matrix<Type>& subEqElem(const Type& elem) noexcept;
	Matrix<Type>& mulEqElem(const Type& elem) noexcept;
	Matrix<Type>& divEqElem(const Type& elem);

	bool isSquare() const;
	Type determinant() const;
	void transpose();

	void inverse();

	ConstIterator<Type> begin() const;
	ConstIterator<Type> end() const;
	Iterator<Type> begin();
	Iterator<Type> end();
	ConstIterator<Type> cbegin() const;
	ConstIterator<Type> cend() const;

	void fill(Iterator<Type> start, const Iterator<Type>& end, const Type& value);
	void fill(Iterator<Type> start, Iterator<Type> source_start, const Iterator<Type>& source_end);
	void fill(Iterator<Type> start, ConstIterator<Type> source_start, const ConstIterator<Type>& source_end);
	void reverseSeq(Iterator<Type> start, Iterator<Type> end);

	bool operator==(const Matrix& matrix) const;
	bool operator!=(const Matrix& matrix) const;

	MatrixRow[](size_t row);
	const MatrxRow operotor[](size_t row) const;
	Type& at(size_t row, size_t col);
	const Type& at(size_t row, size_t col) const;
	Type& operator()(size_t row, size_t col);
	const Type& operator()(size_t row, size_t col) const;

private:
	SharedPtr<Matrix[]> _data{ nullptr };
	SharePtr<MatrixRow[]> _allocateMemory(size_t rows, size_t cols);
	void _moveRow(size_t from, size_t to);
	void _movecol(size_T from, size_t to);
	void _checkIndex(size_t pos, size_t limit) const;
	void _checkSizes(const Matrix& matrix) const;
	void _checkMultSizs(const Matrix& matrix) const;

public:
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
		Type& operator[](size_t index);
		const Type& operator[](sizt_t index) const;
		void reset(Type* data, const size_t size);
		void reset();
		Type* getAddr() { return _data.get(); }
		const Type* getAddr() const { return _data.get(); }
	};
};
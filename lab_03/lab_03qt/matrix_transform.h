#ifndef MATRIX_TRANSFORM_H
#define MATRIX_TRANSFORM_H

#include <cmath>
#include "matrix.h"

class MoveMatrix : public Matrix<double>
{
public:
    bool IsMove() override {return true;};
    MoveMatrix(double x, double y, double z);
};


class ScaleMatrix : public Matrix<double>
{
public:
    bool IsMove() override {return false;};
    ScaleMatrix(double x, double y, double z);
};


class RotateOxMatrix : public Matrix<double>
{
public:
    bool IsMove() override {return false;};
    RotateOxMatrix(double angle);
};


class RotateOyMatrix : public Matrix<double>
{
public:
    bool IsMove() override {return false;};
    RotateOyMatrix(double angle);
};


class RotateOzMatrix : public Matrix<double>
{
public:
    bool IsMove() override {return false;};
    RotateOzMatrix(double angle);
};

#endif // MATRIX_TRANSFORM_H

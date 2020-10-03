#ifndef __MATRIX_H
#define __MATRIX_H

#include <iostream>

class Vector
{
public:
    explicit Vector(int size);

    Vector(const Vector& other);

    ~Vector();

    int getSize() const;

    int& operator[](size_t idx)
    { return data_[idx]; }

    const int& operator[](size_t idx) const
    { return data_[idx]; }

private:
    int size_;
    int* data_;
};

class Matrix
{
public:
    explicit Matrix(int size);

    Matrix(const Matrix& other);

    ~Matrix();

    int getSize() const;

    int& operator[](size_t idx)
    { return data_[idx]; }

    const int& operator[](size_t idx) const
    { return data_[idx]; }


    int size_;
    int* data_;
};

Matrix operator*(Matrix l_mtrx, Matrix const& r_mtrx);

Vector operator*(Matrix mtr, Vector const& vec);

#endif // __MATRIX_H
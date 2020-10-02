#include "matrix.hpp"
#include <algorithm>

#define index(i, j) (((i) * (matrix_size)) + j)

Vector::Vector(int size)
{
    size_ = size;
    data_ = new int[size_];
}

Vector::~Vector()
{
    delete[] data_;
}

int Vector::getSize() const
{
    return size_;
}

Vector::Vector(const Vector& other)
{
    size_ = other.getSize();
    data_ = new int[size_];
    std::copy(other.data_, other.data_ + other.getSize(), data_);
}

Matrix::Matrix(int size)
{
    size_ = size;
    data_ = new int[size_ * size_];
}

int Matrix::getSize() const
{
    return size_;
}

Matrix::~Matrix()
{
    delete[] data_;
}

Matrix::Matrix(const Matrix& other)
{
    size_ = other.getSize();
    data_ = new int[size_ * size_];
    std::copy(other.data_, other.data_ + other.getSize(), data_);
}

Matrix operator*(Matrix l_mtrx, Matrix const& r_mtrx)
{
    int matrix_size = l_mtrx.getSize();
    Matrix v(matrix_size);
    for (int i = 0; i < matrix_size; ++i)
    {
        for (int j = 0; j < matrix_size; ++j)
        {
            v[index(i, j)] = 0;
            for (int k = 0; k < matrix_size; ++k)
            {
                v[index(i, j)] += l_mtrx[index(i, k)] * r_mtrx[index(i, k)];
            }
        }
    }
    return v;
}

Vector operator*(Matrix mtr, Vector const& vec)
{
    int matrix_size = mtr.getSize();
    Vector v(matrix_size);
    for (int i = 0; i < matrix_size; ++i)
    {
        v[i] = 0;
        for (int k = 0; k < matrix_size; ++k)
        {
            v[i] += mtr[index(i, k)] * vec[k];
        }
    }
    return v;
}

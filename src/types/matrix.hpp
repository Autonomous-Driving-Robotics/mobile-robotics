#ifndef TYPES_MATRIX_HPP
#define TYPES_MATRIX_HPP

#include "memory"
#include "tuple"
#include "vector"

namespace stdmath
{

namespace matrix
{

template <typename T>
class Matrix2D
{
  private:
    T* data;
    size_t rows;
    size_t cols;

  public:
    Matrix2D(size_t rows, size_t cols) : rows(rows), cols(cols), data(new T[rows * cols])
    {
        for (size_t t = 0; t < rows * cols; t++)
        {
            data[t] = 0.0;
        }
    }
    ~Matrix2D()
    {
        delete[] data;
    }
    inline T* getData()
    {
        return data;
    }
    inline size_t& getRows()
    {
        return rows;
    }
    inline size_t& getCols()
    {
        return cols;
    }
    inline T& operator()(size_t row, size_t col)
    {
        return data[row * cols + col];
    }
    inline T& operator()(size_t row, size_t col) const
    {
        return data[row * cols + col];
    }
    std::tuple<size_t, size_t> size()
    {
        return std::make_tuple(rows, cols);
    }
};

template <typename T>
class ZerosMatrix : public Matrix2D<T>
{
  public:
    ZerosMatrix(size_t rows, size_t cols) : Matrix2D<T>(rows, cols) {}
    ~ZerosMatrix() {}
};

template <typename T>
class OnesMatrix : public Matrix2D<T>
{
  public:
    OnesMatrix(size_t rows, size_t cols) : Matrix2D<T>(rows, cols)
    {
        T* data = this->getData();
        for (size_t t = 0; t < rows * cols; t++)
        {
            data[t] = 1.0;
        }
    }
    ~OnesMatrix() {}
};

template <typename T>
class SquareMatrix : public Matrix2D<T>
{
  public:
    SquareMatrix(size_t rows) : Matrix2D<T>(rows, rows)
    {
        T* data = this->getData();
        for (size_t t = 0; t < rows * rows; t++)
        {
            data[t] = 0.0;
        }
    }
    ~SquareMatrix() {}
};

template <typename T>
class IdentityMatrix : public Matrix2D<T>
{
  public:
    IdentityMatrix(size_t rows) : Matrix2D<T>(rows, rows)
    {
        T* data = this->getData();
        for (size_t t = 0; t < rows; t++)
        {
            data[t * rows + t] = 1.0;
        }
    }
    ~IdentityMatrix() {}
};

}  // namespace matrix

}  // namespace stdmath

#endif
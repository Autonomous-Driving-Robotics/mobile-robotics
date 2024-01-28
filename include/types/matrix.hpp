#ifndef TYPES_MATRIX_HPP
#define TYPES_MATRIX_HPP

#include "iostream"
#include "memory"
#include "tuple"
#include "vector"

namespace stdmath
{

namespace matrix
{

template <class T>
class VectorXX
{
  protected:
    T* data;

  public:
    VectorXX();
    ~VectorXX();
};

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor = true>
class MatrixXX
{
  protected:
    T* data;

  public:
    MatrixXX();
    ~MatrixXX();
    MatrixXX(std::initializer_list<std::initializer_list<T>> lst);
    std::tuple<size_t, size_t> size() const;
    T& operator()(size_t row, size_t col);
    T operator()(size_t row, size_t col) const;
    size_t rows() const;
    size_t cols() const;
    void resize();
    std::ostream& operator<<(std::ostream os);
};

}  // namespace matrix

}  // namespace stdmath

#endif
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

template <typename T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor = true>
class MatrixXX
{
  protected:
    T* data;

  public:
    MatrixXX();
    ~MatrixXX();
    inline std::tuple<size_t, size_t> size() const;
    inline T& operator()(size_t row, size_t col);
    inline T& operator()(size_t row, size_t col) const;
    inline size_t rows() const;
    inline size_t cols() const;
    void resize();
    std::ostream& operator<<(std::ostream os);
};

}  // namespace matrix

}  // namespace stdmath

#endif
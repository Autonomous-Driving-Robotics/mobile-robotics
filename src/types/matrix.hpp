#ifndef TYPES_MATRIX_HPP
#define TYPES_MATRIX_HPP

#include "iostream"
#include "tuple"
#include "vector"

namespace types
{

struct matrix_size
{
    int rows{0};
    int columns{0};

    friend std::ostream& operator<<(std::ostream& os, const matrix_size& size)
    {
        os << "(" << size.rows << ", " << size.columns << ")\n";
        return os;
    }
};

template <typename T, int rows>
class SquareMatrix
{
  private:
    std::vector<T> matrix;

  public:
    SquareMatrix()
    {
        matrix.resize(rows * rows);
    }

    matrix_size Size()
    {
        return matrix_size{rows, rows};
    }
};

}  // namespace types

#endif
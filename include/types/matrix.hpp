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

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::MatrixXX()
{
    data = new T[numberOfRows * numberOfColumns];
}

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::MatrixXX(
    std::initializer_list<std::initializer_list<T>> lst)
{
    // TODO: Modify the logic to also acoount for Column major code
    data = new T[numberOfRows * numberOfColumns];
    assert(numberOfRows == lst.size());
    int index = 0;
    for (auto row : lst)
    {
        for (auto item : row)
        {
            data[index] = item;
            index++;
        }
    }
}

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::~MatrixXX()
{
    delete[] data;
}

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
std::tuple<size_t, size_t> MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::size() const
{
    return std::make_tuple(numberOfRows, numberOfColumns);
}

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
inline T& MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::operator()(size_t row, size_t col)
{
    return data[row * numberOfColumns + col];
}

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
inline T MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::operator()(size_t row,
                                                                          size_t col) const
{
    return data[row * numberOfColumns + col];
}

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
inline size_t MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::rows() const
{
    return numberOfRows;
}

template <class T, size_t numberOfRows, size_t numberOfColumns, bool rowMajor>
inline size_t MatrixXX<T, numberOfRows, numberOfColumns, rowMajor>::cols() const
{
    return numberOfColumns;
}

}  // namespace matrix

}  // namespace stdmath

#endif
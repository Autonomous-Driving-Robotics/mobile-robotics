#ifndef TYPES_VECTOR_HPP
#define TYPES_VECTOR_HPP

#include "matrix.hpp"

namespace stdmath
{

namespace vector
{

template <class T, size_t numberOfRows>
class VectorXX : public stdmath::matrix::MatrixXX<T, numberOfRows, 1>
{
  private:
    T* data;

  public:
    VectorXX()
    {
        data = new T[numberOfRows];
    }
    ~VectorXX()
    {
        delete[] data;
    }
    VectorXX(std::initializer_list<T> lst)
    {
        data = new T[numberOfRows];
        size_t index{0};
        for (auto element : lst)
        {
            data[index] = element;
            index++;
        }
    }
    T& operator()(size_t index)
    {
        return data[index];
    }
    T operator()(size_t index) const
    {
        return data[index];
    }
};

template <size_t numberOfRows>
using VectorXf = VectorXX<float, numberOfRows>;

template <size_t numberOfRows>
using VectorXd = VectorXX<double, numberOfRows>;

}  // namespace vector

}  // namespace stdmath

#endif
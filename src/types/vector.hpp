#ifndef TYPES_VECTOR_HPP
#define TYPES_VECTOR_HPP

#include "vector"

namespace types
{

template <typename T, int number_of_elements>
class FixedSizeVector
{
  private:
    std::vector<T> v;

  public:
    int Size()
    {
        return v.size();
    }
    FixedSizeVector()
    {
        v.resize(number_of_elements);
    }
};

}  // namespace types

#endif
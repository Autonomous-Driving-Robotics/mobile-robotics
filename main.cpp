#include "iostream"
#include "src/particle_filter/particle_filter.hpp"
#include "src/types/matrix.hpp"
#include "src/types/vector.hpp"

int main()
{
    types::FixedSizeVector<float, 2> A;
    std::cout << A.Size() << std::endl;

    types::SquareMatrix<float, 2> B;
    std::cout << B.Size();
    return 0;
}
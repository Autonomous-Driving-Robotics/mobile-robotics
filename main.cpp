#include "iostream"
#include "src/types/matrix.hpp"
#include "src/types/vector.hpp"

int main()
{
    types::FixedSizeVector<float, 2> A;
    std::cout << A.Size() << std::endl;

    stdmath::matrix::ZerosMatrix<float> B(2, 2);
    std::cout << "[[" << B(0, 0) << ", " << B(0, 1) << "],\n[" << B(1, 0) << ", " << B(1, 1)
              << "]]\n";
    auto shape{B.size()};
    return 0;
}
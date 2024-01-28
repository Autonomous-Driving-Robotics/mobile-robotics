#include "matrix.hpp"

#include "particle_filter.hpp"

// #include "../src/types/src/matrix.cpp"
#include "gtest/gtest.h"

TEST(MatrixTest, CheckSize)
{
    stdmath::matrix::MatrixXX<double, 3, 4> test_matrix;
    EXPECT_EQ(test_matrix.size(), std::make_tuple(3, 4));
}

// TEST(MatrixTest, CheckNumberOfRows)
// {
//     stdmath::matrix::MatrixXX<double, 3, 4> test_matrix;
//     EXPECT_EQ(test_matrix.rows(), 3);
// }

// TEST(MatrixTest, CheckNumberOfColumns)
// {
//     stdmath::matrix::MatrixXX<double, 3, 4> test_matrix;
//     EXPECT_EQ(test_matrix.cols(), 4);
// }

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
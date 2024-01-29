#include "matrix.hpp"

#include "gtest/gtest.h"

TEST(MatrixTest, CheckSize)
{
    stdmath::matrix::MatrixXX<double, 3, 4> test_matrix;
    EXPECT_EQ(test_matrix.size(), std::make_tuple(3, 4));
}

TEST(MatrixTest, CheckNumberOfRows)
{
    stdmath::matrix::MatrixXX<double, 3, 4> test_matrix;
    EXPECT_EQ(test_matrix.rows(), 3);
}

TEST(MatrixTest, CheckNumberOfColumns)
{
    stdmath::matrix::MatrixXX<double, 3, 4> test_matrix;
    EXPECT_EQ(test_matrix.cols(), 4);
}

TEST(MatrixTest, InitializerListContructorTest)
{
    stdmath::matrix::MatrixXX<double, 3, 4> test_matrix = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    EXPECT_EQ(test_matrix(1, 3), 8);

    test_matrix(1, 3) = 0;
    EXPECT_EQ(test_matrix(1, 3), 0);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
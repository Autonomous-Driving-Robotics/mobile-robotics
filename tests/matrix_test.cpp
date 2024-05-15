#include "matrix.hpp"

#include "gtest/gtest.h"
#include "iostream"

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

TEST(MatrixTest, FloatMatrixTest)
{
    stdmath::matrix::MatrixXf<2, 3> test_matrix{{{1, 2, 3}, {4, 5, 6}}};
    EXPECT_EQ(test_matrix.size(), std::make_tuple(2, 3));
    EXPECT_EQ(typeid(test_matrix(0, 0)), typeid(float));
}

TEST(MatrixTest, DoubleMatrixTest)
{
    stdmath::matrix::MatrixXd<2, 3> test_matrix{{{1, 2, 3}, {4, 5, 6}}};
    EXPECT_EQ(test_matrix.size(), std::make_tuple(2, 3));
    EXPECT_EQ(typeid(test_matrix(0, 0)), typeid(double));
}

TEST(MatrixTest, FloatSquareMatrixTest)
{
    stdmath::matrix::MatrixXf<2, 2> test_matrix{{{1, 2}, {4, 5}}};
    EXPECT_EQ(test_matrix.size(), std::make_tuple(2, 2));
    EXPECT_EQ(typeid(test_matrix(0, 0)), typeid(float));
}

TEST(MatrixTest, DoubleSquareMatrixTest)
{
    stdmath::matrix::MatrixXd<2, 2> test_matrix{{{1, 2}, {4, 5}}};
    EXPECT_EQ(test_matrix.size(), std::make_tuple(2, 2));
    EXPECT_EQ(typeid(test_matrix(0, 0)), typeid(double));
}

TEST(MatrixTest, EqualityTest)
{
    stdmath::matrix::MatrixXd<2, 2> test_matrix1{{{1, 2}, {4, 5}}};
    stdmath::matrix::MatrixXd<2, 2> test_matrix2{{{1, 2}, {4, 5}}};
    stdmath::matrix::MatrixXd<2, 2> test_matrix3{{{2, 1}, {3, 0}}};

    EXPECT_TRUE(test_matrix1 == test_matrix2);
    EXPECT_FALSE(test_matrix1 == test_matrix3);

    EXPECT_FALSE(test_matrix1 != test_matrix2);
    EXPECT_TRUE(test_matrix1 != test_matrix3);
}

TEST(MatrixTest, AddTwoMatrix)
{
    stdmath::matrix::MatrixXd<2, 2> test_matrix1{{{1, 2}, {4, 5}}};
    stdmath::matrix::MatrixXd<2, 2> test_matrix2{{{2, 1}, {3, 0}}};
    stdmath::matrix::MatrixXd<2, 2> res1{{{3, 3}, {7, 5}}};
    EXPECT_TRUE(res1 == (test_matrix1 + test_matrix2));

    stdmath::matrix::MatrixXd<2, 2> res2{{{3, 1}, {7, 0}}};
    EXPECT_FALSE(res2 == (test_matrix1 + test_matrix2));
}

TEST(MatrixTest, SubtractTwoMatrix)
{
    stdmath::matrix::MatrixXd<2, 2> test_matrix1{{{1, 2}, {4, 5}}};
    stdmath::matrix::MatrixXd<2, 2> test_matrix2{{{2, 1}, {3, 0}}};
    stdmath::matrix::MatrixXd<2, 2> res1{{{-1, 1}, {1, 5}}};
    EXPECT_TRUE(res1 == (test_matrix1 - test_matrix2));

    stdmath::matrix::MatrixXd<2, 2> res2{{{3, 1}, {7, 0}}};
    EXPECT_FALSE(res2 == (test_matrix1 - test_matrix2));
}

TEST(MatrixTest, AddCompoundOperator)
{
    stdmath::matrix::MatrixXd<2, 2> test_matrix1{{{1, 2}, {4, 5}}};
    stdmath::matrix::MatrixXd<2, 2> test_matrix2{{{2, 1}, {3, 0}}};
    test_matrix1 += test_matrix2;
    stdmath::matrix::MatrixXd<2, 2> res1{{{3, 3}, {7, 5}}};
    EXPECT_TRUE(res1 == test_matrix1);

    stdmath::matrix::MatrixXd<2, 2> res2{{{3, 1}, {7, 0}}};
    EXPECT_FALSE(res2 == test_matrix1);
}

TEST(MatrixTest, SubtractCompoundOperator)
{
    stdmath::matrix::MatrixXd<2, 2> test_matrix1{{{1, 2}, {4, 5}}};
    stdmath::matrix::MatrixXd<2, 2> test_matrix2{{{2, 1}, {3, 0}}};
    test_matrix1 -= test_matrix2;
    stdmath::matrix::MatrixXd<2, 2> res1{{{-1, 1}, {1, 5}}};
    EXPECT_TRUE(res1 == test_matrix1);

    stdmath::matrix::MatrixXd<2, 2> res2{{{3, 1}, {7, 0}}};
    EXPECT_FALSE(res2 == test_matrix1);
}

TEST(MatrixTest, UnarySubtractOperator)
{
    stdmath::matrix::MatrixXd<2, 2> test_matrix{{{1, 2}, {4, 5}}};
    stdmath::matrix::MatrixXd<2, 2> res1{{{-1, -2}, {-4, -5}}};
    EXPECT_TRUE(res1 == -test_matrix);

    // stdmath::matrix::MatrixXd<2, 2> res2{{{3, 1}, {7, 0}}};
    // EXPECT_FALSE(res2 == test_matrix);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
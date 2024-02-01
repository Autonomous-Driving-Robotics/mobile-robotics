#include "gtest/gtest.h"
#include "iostream"
#include "matrix.hpp"

TEST(VectorTest, CheckSize)
{
    stdmath::matrix::VectorXX<double, 3> test_vector;
    EXPECT_EQ(test_vector.size(), std::make_tuple(3, 1));
}

TEST(VectorTest, CheckNumberOfRows)
{
    stdmath::matrix::VectorXX<double, 3> test_vector;
    EXPECT_EQ(test_vector.rows(), 3);
}

TEST(VectorTest, CheckNumberOfColumns)
{
    stdmath::matrix::VectorXX<double, 3> test_vector;
    EXPECT_EQ(test_vector.cols(), 1);
}

TEST(VectorTest, InitializerListContructorTest)
{
    stdmath::matrix::VectorXX<double, 4> test_vector = {1, 2, 3, 4};
    EXPECT_EQ(test_vector(1), 2);

    test_vector(3) = 0;
    EXPECT_EQ(test_vector(3), 0);
}

TEST(VectorTest, FloatVectorTest)
{
    stdmath::matrix::VectorXf<2> test_vector{{1, 2}};
    EXPECT_EQ(test_vector.size(), std::make_tuple(2, 1));
    EXPECT_EQ(typeid(test_vector(0)), typeid(float));
}

TEST(VectorTest, DoubleVectorTest)
{
    stdmath::matrix::VectorXd<2> test_vector{{1, 2}};
    EXPECT_EQ(test_vector.size(), std::make_tuple(2, 1));
    EXPECT_EQ(typeid(test_vector(0)), typeid(double));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
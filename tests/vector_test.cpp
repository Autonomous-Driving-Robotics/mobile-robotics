#include "vector.hpp"

#include "gtest/gtest.h"
#include "iostream"

TEST(VectorTest, CheckSize)
{
    stdmath::vector::VectorXX<double, 3> test_vector;
    EXPECT_EQ(test_vector.size(), std::make_tuple(3, 1));
}

TEST(VectorTest, CheckNumberOfRows)
{
    stdmath::vector::VectorXX<double, 3> test_vector;
    EXPECT_EQ(test_vector.rows(), 3);
}

TEST(VectorTest, CheckNumberOfColumns)
{
    stdmath::vector::VectorXX<double, 3> test_vector;
    EXPECT_EQ(test_vector.cols(), 1);
}

TEST(VectorTest, InitializerListContructorTest)
{
    stdmath::vector::VectorXX<double, 4> test_vector = {1, 2, 3, 4};
    EXPECT_EQ(test_vector[1], 2);

    test_vector[3] = 0;
    EXPECT_EQ(test_vector[3], 0);
}

TEST(VectorTest, FloatVectorTest)
{
    stdmath::vector::VectorXf<2> test_vector{{1, 2}};
    EXPECT_EQ(test_vector.size(), std::make_tuple(2, 1));
    EXPECT_EQ(typeid(test_vector[0]), typeid(float));
}

TEST(VectorTest, DoubleVectorTest)
{
    stdmath::vector::VectorXd<2> test_vector{{1, 2}};
    EXPECT_EQ(test_vector.size(), std::make_tuple(2, 1));
    EXPECT_EQ(typeid(test_vector[0]), typeid(double));
}

TEST(VectorTest, AddTwoVectors)
{
    stdmath::vector::VectorXd<2> test_vector1{{1, 2}};
    stdmath::vector::VectorXd<2> test_vector2{{3, 4}};
    // stdmath::vector::VectorXd<2> res = test_vector1 + test_vector2;
    // EXPECT_EQ(res, stdmath::vector::VectorXd<2>{{4, 6}});
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
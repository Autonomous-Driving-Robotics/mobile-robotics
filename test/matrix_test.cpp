#include "matrix.hpp"

#include "gtest/gtest.h"

TEST(MatrixTest, BasicAssertions)
{
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}

TEST(MatrixTest, AnotherAssertion)
{
    EXPECT_EQ(1, 2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
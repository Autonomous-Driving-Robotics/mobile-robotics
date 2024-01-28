cmake_minimum_required(VERSION 3.16)
project(mobile_robotics)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(include)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

include(GoogleTest)

add_executable(matrix_test tests/matrix_test.cpp)

target_link_libraries(matrix_test
    PRIVATE
    GTest::GTest
    matrix
    bayes_filter)

gtest_discover_tests(matrix_test)
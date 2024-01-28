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

add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test
    PRIVATE
    GTest::GTest
    matrix
    bayes_filter)
gtest_discover_tests(matrix_test)

add_executable(bayes_filter_test bayes_filter_test.cpp)
target_link_libraries(bayes_filter_test
    PRIVATE
    GTest::GTest
    matrix
    bayes_filter)
gtest_discover_tests(bayes_filter_test)
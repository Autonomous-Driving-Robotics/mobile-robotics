cmake_minimum_required(VERSION 3.16)
project(mobile_robotics VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(tests)
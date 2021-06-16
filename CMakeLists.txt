cmake_minimum_required(VERSION 3.18)
project(iterator)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
    set(CMAKE_CXX_FLAGS -pthread)
endif()

add_executable(grid grid.cpp)

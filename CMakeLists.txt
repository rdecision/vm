cmake_minimum_required(VERSION 4.0)
project(vm)

set(CMAKE_CXX_STANDARD 20)

add_library(core src/core/chunk.cpp)

add_executable(vm src/main.cpp)

target_include_directories(vm
    PRIVATE include)


cmake_minimum_required(VERSION 3.0)

project(timing_exercises)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
add_executable(Sort src/sorting.cpp)
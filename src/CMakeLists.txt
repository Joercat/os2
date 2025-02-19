cmake_minimum_required(VERSION 3.10)
project(SimpleOS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(os src/main.cpp)

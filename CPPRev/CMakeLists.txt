cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 23)


project(myProject)
add_executable(a main.cpp)
target_compile_options(a PRIVATE -Wall)
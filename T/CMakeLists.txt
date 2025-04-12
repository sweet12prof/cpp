cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_C_COMPILER cl)
#set(CMAKE_CXX_COMPILER cl)
project(MyProject)
add_executable(a some.cpp)

target_compile_definitions(a PRIVATE -Wall)

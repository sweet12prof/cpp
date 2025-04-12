cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_COMPILER cl)
set(CMAKE_CXX_COMPILER cl)
project(spanRev)
add_executable(a main.cpp Acc.cpp)
#target_link_libraries()

target_compile_definitions(a PRIVATE -Wall)
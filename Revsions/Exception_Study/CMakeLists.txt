cmake_minimum_required(VERSION 3.18)

project(MyProject VERSION 0.0)

add_library(Headers 
./DivideByZero_derivedException.h)

add_executable(${PROJECT_NAME}
exceptionsStudy.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC Headers)


cmake_minimum_required(VERSION 3.25)

project(
        PolyOO 
        VERSION 0.0
        DESCRIPTION "Using Operator Overloading to implement a Polynomial Class" 
        LANGUAGES CXX
    )

add_executable(
                poly
                src/Poly.cpp
                main.cpp
)   

target_compile_features(poly PRIVATE cxx_std_20)

target_include_directories( poly PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
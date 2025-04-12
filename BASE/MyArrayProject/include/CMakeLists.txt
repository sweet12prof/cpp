add_library(
    MyArrayLib
    hpp/Myarray.hpp
    cpp/MyArray.cpp
)
target_include_directories( MyArrayLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpp)

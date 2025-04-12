add_executable(main main.cpp)
target_compile_options(main PRIVATE -Wall)
target_link_libraries(main PRIVATE MyArrayLib)

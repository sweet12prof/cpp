            add_library(
                A_lib
                hpp/bClass.hpp
                cpp/bClass.cpp        
            )
            target_include_directories(A_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpp)

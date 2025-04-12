add_library(
            helloLib
            HelloLibs/hpp/hello.hpp 
            HelloLibs/cpp/hello.cpp 
        )
        
target_include_directories(helloLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/HelloLibs" )
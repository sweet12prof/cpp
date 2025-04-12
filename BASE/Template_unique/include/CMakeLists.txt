add_library(
    uniqLib STATIC
    headers/uniqPtr.hpp
    src/uniqPtr.cpp
)   


target_include_directories(uniqLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
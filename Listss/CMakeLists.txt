cmake_minimum_required(VERSION 3.20)
project(ListProj)
# add_library(
#     dlistLib
#     dlist.hpp
# # )
# target_include_directories(dlistLib  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
if(MSVC)
    set(ASM_OUTPUT_DIR "${CMAKE_BINARY_DIR}/Output")

    file(MAKE_DIRECTORY ${ASM_OUTPUT_DIR})  # Ensure it exists

   add_compile_options(/FAs /Fa${ASM_OUTPUT_DIR}/)
endif()

# add_library(dListLib 
#             dList.hpp
#             dList.cpp)  
add_executable(main main.cpp)


#set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Output")
# target_include_directories(dListLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
target_include_directories(main  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)
# target_link_libraries(main PRIVATE dlistLib)
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(fillit C)

file(GLOB_RECURSE fillit_HDRS ${fillit_HDRS} include/*.h)
file(GLOB fillit_SRCS ${fillit_SRCS} src/*.c)

add_executable(fillit ${fillit_HDRS} ${fillit_SRCS})
add_dependencies(fillit ft)
target_include_directories(fillit PUBLIC include)
target_link_libraries(fillit ft)

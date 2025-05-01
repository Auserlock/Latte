cmake_minimum_required(VERSION 3.30)
project(Latte)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE LATTE_HEADER_FILES
        ${CMAKE_SOURCE_DIR}/include/*.hpp
)
file(GLOB_RECURSE UTIL_SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/util/*.cpp
)

add_executable(Latte
        src/main.cpp
        src/core/mem.cpp
        include/core/mem.hpp
)

target_include_directories(
        Latte
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/util
        ${CMAKE_SOURCE_DIR}/include/core/framework
)
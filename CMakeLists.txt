cmake_minimum_required(VERSION 3.30)
project(Latte)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE LATTE_HEADER_FILES
        ${CMAKE_SOURCE_DIR}/include/*.hpp
)
file(GLOB_RECURSE UTIL_SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/util/*.cc
)
file(GLOB_RECURSE CORE_SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/core/*.cc
)

add_library(
        LatteDependency
        SHARED
        ${CORE_SOURCE_FILES}
        ${UTIL_SOURCE_FILES}
        ${LATTE_HEADER_FILES}
)

target_include_directories(
        LatteDependency
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

add_executable(
        Latte
        src/main.cpp
)

target_link_libraries(
        Latte
        PRIVATE
        LatteDependency
)

target_include_directories(
        Latte
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

ADD_DEPENDENCIES(
        Latte
        LatteDependency
)
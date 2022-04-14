cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME tsa)
set(PROJECT_SOURCE_DIR .)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/source
)

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/include/*.hpp
    ${PROJECT_SOURCE_DIR}/source/*.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
add_executable(${PROJECT_NAME}_threads main_threads.cpp ${SOURCES})

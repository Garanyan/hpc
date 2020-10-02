cmake_minimum_required(VERSION 3.5)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(Matrix)

add_library(LibMatrix STATIC
        matrix.cpp)

# CMake instructions to test using the static lib
SET( APP_EXE StaticTest )

add_executable(${PROJECT_NAME}
        main.cpp)

target_link_libraries(${PROJECT_NAME} LibMatrix)

install(TARGETS LibMatrix DESTINATION ${CMAKE_BINARY_DIR})
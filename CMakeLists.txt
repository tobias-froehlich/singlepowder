cmake_minimum_required(VERSION 3.5.1)
project(singlepowder VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)
configure_file(src/singlepowderConfig.h.in singlepowderConfig.h)

add_subdirectory(test)

target_include_directories(singlepowder PUBLIC "${PROJECT_BINARY_DIR}")

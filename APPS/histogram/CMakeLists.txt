cmake_minimum_required(VERSION 3.22.1)

project(histogram
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory("UTILS")

add_executable(histo.exe main.cpp)

target_link_libraries(histo.exe rand_init)

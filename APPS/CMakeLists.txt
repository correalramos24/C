cmake_minimum_required(VERSION 3.22.1)

project(myC++_Apps
        VERSION 1.0
        LANGUAGES CXX)

# Histogram
set(HISTO_EXE_NAME histo.exe)
add_executable(${HISTO_EXE_NAME} histogram/main.cpp)

# Histogram libraries:
add_subdirectory(UTILS)
target_link_libraries(${HISTO_EXE_NAME} PUBLIC rand_init)
target_include_directories(${HISTO_EXE_NAME} PUBLIC UTILS/include)
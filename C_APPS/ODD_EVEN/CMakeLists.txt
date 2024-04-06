cmake_minimum_required(VERSION 3.20)

# Define project name
project(odd_even C)

add_executable( ${PROJECT_NAME} main_odd_even.c )

find_package(OpenMP)
if(OpenMP_C_FOUND)
    set(OMP_BIN ${PROJECT_NAME}_OMP)
    add_executable( ${OMP_BIN} main_odd_even.c)
    target_compile_options( ${OMP_BIN} PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries( ${OMP_BIN} PRIVATE ${OpenMP_C_FLAGS})
endif()
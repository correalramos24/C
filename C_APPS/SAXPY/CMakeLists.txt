
# Define CMake version
cmake_minimum_required(VERSION 3.20)

# Define project name
project(saxpy C)

find_package(OpenMP)

add_executable( ${PROJECT_NAME} main_saxpy.c )

add_executable( "${PROJECT_NAME}_double" main_saxpy.c )
target_compile_definitions("${PROJECT_NAME}_double" PRIVATE DOUBLE_PREC)

if(OpenMP_C_FOUND)
    add_executable( "${PROJECT_NAME}_omp" main_saxpy.c )
    target_compile_options("${PROJECT_NAME}_omp" PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries("${PROJECT_NAME}_omp" PRIVATE ${OpenMP_C_FLAGS})

    add_executable( "${PROJECT_NAME}_double_omp" main_saxpy.c )
    target_compile_definitions("${PROJECT_NAME}_double_omp" PRIVATE DOUBLE_PREC)
    target_compile_options("${PROJECT_NAME}_double_omp" PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries("${PROJECT_NAME}_double_omp" PRIVATE ${OpenMP_C_FLAGS})
endif()

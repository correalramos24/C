
# Define CMake version
cmake_minimum_required(VERSION 3.20)

# Define project name
project(saxpy C)

set(OMP ${PROJECT_NAME}_omp)
SET(DB_PREC ${PROJECT_NAME}_double)
set(DB_PREC_OMP ${PROJECT_NAME}_double_omp)

add_executable( ${PROJECT_NAME} main_saxpy.c )

add_executable( ${DB_PREC} main_saxpy.c )
target_compile_definitions( ${DB_PREC} PRIVATE DOUBLE_PREC)

find_package(OpenMP)
if(OpenMP_C_FOUND)
    add_executable( DB_PREC_OMP main_saxpy.c )
    target_compile_options(DB_PREC_OMP PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries(DB_PREC_OMP PRIVATE ${OpenMP_C_FLAGS})

    add_executable( ${DB_PREC_OMP} main_saxpy.c )
    target_compile_definitions(${DB_PREC_OMP} PRIVATE DOUBLE_PREC)
    target_compile_options(${DB_PREC_OMP} PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries( ${DB_PREC_OMP} PRIVATE ${OpenMP_C_FLAGS})
endif()

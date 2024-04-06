# Define CMake version
cmake_minimum_required(VERSION 3.20)

# Define project name
project(sieve C)

set(IO_BIN ${PROJECT_NAME}_io)

add_executable( ${PROJECT_NAME} main_sieve.c )

add_executable( ${IO_BIN} main_sieve.c )
target_compile_definitions(${IO_BIN} PRIVATE _IO=1)


find_package(OpenMP)
if(OpenMP_C_FOUND)
    set(OMP_BIN ${PROJECT_NAME}_omp)
    set(IO_OMP_BIN ${PROJECT_NAME}_io_omp)
    add_executable( ${OMP_BIN} main_sieve.c)
    target_compile_options("${OMP_BIN}" PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries("${OMP_BIN}" PRIVATE ${OpenMP_C_FLAGS})


    add_executable( ${IO_OMP_BIN} main_sieve.c)
    target_compile_definitions(${IO_OMP_BIN} PRIVATE _IO=1)
    target_compile_options(${IO_OMP_BIN} PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries(${IO_OMP_BIN} PRIVATE ${OpenMP_C_FLAGS})


endif()
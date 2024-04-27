# Define CMake version
cmake_minimum_required(VERSION 3.20)

# Define project name
project(exp_calc C)

set(BIN_BASE ${PROJECT_NAME}_baseline)
set(BIN_NEW ${PROJECT_NAME}_new)

add_executable( ${BIN_BASE} main_exp.c )
# Link with math library -lm
target_link_libraries(${BIN_BASE} PRIVATE m)

add_executable( ${BIN_NEW} main_exp.c )
target_compile_definitions( ${BIN_NEW} PRIVATE NEW)
target_link_libraries(${BIN_NEW} PRIVATE m)

# Define CMake version
cmake_minimum_required(VERSION 3.20)

# Define project name
project(exp_calc C)

add_executable( ${PROJECT_NAME} main_exp.c )
# Link with math library -lm
target_link_libraries(${PROJECT_NAME} PRIVATE m)
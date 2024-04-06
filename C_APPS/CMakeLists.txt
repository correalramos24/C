
# Define CMake version
cmake_minimum_required(VERSION 3.20)

# Define project name
project(bench_apps C)

# Version management
# set(VESION_MAJOR 1)
# set(VERSION_MINOR 0)

include_directories("UTILS/include")

# Add subdirs:
add_subdirectory(SAXPY)
add_subdirectory(VEC_ADD)
add_subdirectory(EXP)
add_subdirectory(ODD_EVEN)
add_subdirectory(SIEVE)
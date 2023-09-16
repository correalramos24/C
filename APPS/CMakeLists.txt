cmake_minimum_required(VERSION 3.22.1)

project(myC++_Apps
        VERSION 1.0
        LANGUAGES CXX)


# ################################# Histogram ##################################
set(HISTO_EXE_NAME histo.exe)
add_executable(${HISTO_EXE_NAME} histogram/main.cpp)

# Histogram libraries:
add_subdirectory(UTILS)
target_link_libraries(${HISTO_EXE_NAME} PUBLIC rand_init)
target_include_directories(${HISTO_EXE_NAME} PUBLIC UTILS/include)

# Histogram OpenMP
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
        set(HISTO_OMP_TARGET histo_OMP.exe)
        add_executable(${HISTO_OMP_TARGET} histogram/main.cpp)
        target_link_libraries(${HISTO_OMP_TARGET} PUBLIC OpenMP::OpenMP_CXX)

        # Histogram libraries:
        target_link_libraries(${HISTO_OMP_TARGET} PUBLIC rand_init)
        target_include_directories(${HISTO_OMP_TARGET} PUBLIC UTILS/include)
endif()

# ################################# Histogram ##################################

# ############################### Sorting Algs #################################

set(SORTING_EXE_NAME sort.exe)
add_executable(${SORTING_EXE_NAME} Sorting/main.cpp)



# ############################### Sorting Algs #################################

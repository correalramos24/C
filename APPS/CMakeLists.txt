cmake_minimum_required(VERSION 3.22.1)

project(myC++_Apps
        VERSION 1.0
        LANGUAGES CXX C)


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
# ############################### Sorting Algs ################################

# ############################ Erathostenes Sieve ################################
set(SIEVE_EXE_NAME sieve.exe)
add_executable(${SIEVE_EXE_NAME} SIEVE/main.c)
target_link_libraries(${SIEVE_EXE_NAME} PUBLIC timing)
target_include_directories(${SIEVE_EXE_NAME} PUBLIC UTILS/include)

set(SIEVE_EXE_IO sieve_io.exe)
add_executable(${SIEVE_EXE_IO} SIEVE/main.c)
target_compile_definitions(${SIEVE_EXE_IO} PUBLIC _IO=1)
target_link_libraries(${SIEVE_EXE_IO} PUBLIC timing)
target_include_directories(${SIEVE_EXE_IO} PUBLIC UTILS/include)
# ############################ Erathostenes Sieve ################################

# ################################### SAXPY ######################################
set(SAXPY_EXE_NAME saxpy.exe)
add_executable(${SAXPY_EXE_NAME} SAXPY/main.c)
target_link_libraries(${SAXPY_EXE_NAME} PUBLIC timing)
target_include_directories(${SAXPY_EXE_NAME} PUBLIC UTILS/include)
# ################################### SAXPY ######################################

# ################################## VEC_ADD #####################################
set(VEC_ADD_EXE_NAME vec_add.exe)
add_executable(${VEC_ADD_EXE_NAME} VEC_ADD/main.c)
target_link_libraries(${VEC_ADD_EXE_NAME} PUBLIC timing)
target_link_libraries(${VEC_ADD_EXE_NAME} PUBLIC random_init_c)
target_include_directories(${VEC_ADD_EXE_NAME} PUBLIC UTILS/include)


find_package(OpenMP)
if(OpenMP_CXX_FOUND)
        set(VEC_ADD_OMP_TARGET vec_add_OMP.exe)
        add_executable(${VEC_ADD_OMP_TARGET} VEC_ADD/main.c)
        target_link_libraries(${VEC_ADD_OMP_TARGET} PUBLIC OpenMP::OpenMP_C)

        # libraries:
        target_link_libraries(${VEC_ADD_OMP_TARGET} PUBLIC timing)
        target_link_libraries(${VEC_ADD_OMP_TARGET} PUBLIC random_init_c)
        target_include_directories(${VEC_ADD_OMP_TARGET} PUBLIC UTILS/include)

endif()
# ################################## VEC_ADD #####################################

# ################################## EVEN_ODD ####################################
set(ODD_EVEN_EXE_NAME odd_even.exe)
add_executable(${ODD_EVEN_EXE_NAME} ODD_EVEN/main.c)
target_link_libraries(${ODD_EVEN_EXE_NAME} PUBLIC timing)
target_link_libraries(${ODD_EVEN_EXE_NAME} PUBLIC random_init_c)
target_include_directories(${ODD_EVEN_EXE_NAME} PUBLIC UTILS/include)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
        set(ODD_EVEN_OMP_NAME odd_even_OMP.exe)
        add_executable(${ODD_EVEN_OMP_NAME} ODD_EVEN/main.c)
        target_link_libraries(${ODD_EVEN_OMP_NAME} PUBLIC OpenMP::OpenMP_C)

        # libraries:
        target_link_libraries(${ODD_EVEN_OMP_NAME} PUBLIC timing)
        target_link_libraries(${ODD_EVEN_OMP_NAME} PUBLIC random_init_c)
        target_include_directories(${ODD_EVEN_OMP_NAME} PUBLIC UTILS/include)

endif()

# ################################## EVEN_ODD ####################################


# ################################## EXP #######################################
set(EXP_EXE_NAME exp.exe)
add_executable(${EXP_EXE_NAME} EXP/main.c)
target_link_libraries(${EXP_EXE_NAME} PUBLIC timing)
target_link_libraries(${EXP_EXE_NAME} PUBLIC io_helper)
target_include_directories(${EXP_EXE_NAME} PUBLIC UTILS/include)

# ################################## EXP #######################################


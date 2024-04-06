
# Define CMake version
cmake_minimum_required(VERSION 3.20)

# Define project name
project(vec_add C)

set(OMP ${PROJECT_NAME}_omp)
set(REC ${PROJECT_NAME}_rec)
set(REC_OMP ${PROJECT_NAME}_rec_omp)

add_executable( ${PROJECT_NAME} main_vec_add.c vec_add_iter.c )

add_executable( ${REC} main_vec_add.c vec_add_rec.c )
target_compile_definitions(${REC} PRIVATE REC_VERSION)

find_package(OpenMP)
if(OpenMP_C_FOUND)
    add_executable( ${OMP} main_vec_add.c vec_add_iter.c )
    target_compile_options(${OMP} PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries(${OMP} PRIVATE ${OpenMP_C_FLAGS})

    
    add_executable( ${REC_OMP}  main_vec_add.c vec_add_rec.c )
    target_compile_definitions(${REC_OMP} PRIVATE REC_VERSION)
    target_compile_options(${REC_OMP} PRIVATE ${OpenMP_C_FLAGS})
    target_link_libraries(${REC_OMP} PRIVATE ${OpenMP_C_FLAGS})
    
endif()
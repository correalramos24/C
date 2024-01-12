cmake_minimum_required(VERSION 3.22.1)

project(cplusplus_utils
        VERSION 1.0
        LANGUAGES CXX)

set(SOURCES_rand_init src/rand_init.cpp)
set(HEADERS_rand_init include/rand_init.hh)

add_library(rand_init ${SOURCES_rand_init} ${HEADERS_rand_init})
target_include_directories(rand_init PUBLIC include)

add_library(timing src/timing.c include/timing.h)
target_include_directories(timing PUBLIC include)

add_library(random_init_c src/random_init.c include/random_init.h)
target_include_directories(random_init_c PUBLIC include)
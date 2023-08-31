cmake_minimum_required(VERSION 3.22.1)

project(cplusplus_utils
        VERSION 1.0
        LANGUAGES CXX)

set(SOURCES src/rand_init.cpp)
set(HEADERS include/rand_init.hh)

add_library(rand_init ${SOURCES} ${HEADERS})
target_include_directories(rand_init PUBLIC include)
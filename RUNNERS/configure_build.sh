#!/bin/bash

cd ../C_APPS

if [ -d build ]; then
    echo "Build directory already exists. Abort"
    exit 1
fi

# Create build directory:
mkdir build && cd build

# Configure && compile with CMake:
cmake .. && make

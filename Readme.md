
# C

Just **C/C++** applications with **CMake** compilation environment.

Aims to be used for trying CTest and also the deploy of the CI/CD pipelines.

# APPS
Available apps in C++ mainly, used for being used as a benchmark. 
All the APPS can run in single core (CPU), with multithreading (OMP) or with
distributed computation approach (MPI). 

1. SAXPY : SAXPY (Single precision A X plus Y) benchmark. [CPU, OMP]
2. Histogram : Histogram from a random input. [CPU]
3. Sorting : random sorting with different sorting algorithms. [CPU]

## Build the apps
All the apps can be built with CMAKE.


## Ideas to implement

* Random numbers generator (for uses as input files)

* Sorting algorithms (bubble sort, merge sort, counting sort)

* Pi computation (OMP and MPI)

* Fibonnaci (with dynamic programming)

* Some *stencil* with dependencies
  

## Utils to implement 
* Benchmark arguments for all the APPS.
* Complete benchmark of all the APPS.
* Timing functions (in pure C).
* logging functions (in pure C).

# Other TODO
* Add badges with the OMP, MPI etc..
* Add documentation with Github pages from my notes.
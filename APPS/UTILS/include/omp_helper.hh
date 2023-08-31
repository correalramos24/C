#ifndef __OMP_HELPER__
#define __OMP_HELPER__

#include <iostream>

using namespace std;

void check_omp_enabled(){
    #ifdef _OPENMP
        cout << "OpenMP enabled!" << endl;
    #else
        cout << "OpenMP disabled!" << endl;
    #endif
}

#endif
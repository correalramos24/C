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

int omp_get_num_threads_safe(){
    #ifdef _OPENMP
        return omp_get_num_threads();
    #else
        cout << "WARNING! OMP DISABLED" << endl;
        return 1;
    #endif
}

#endif

#include <stdio.h>
#include <omp.h>


void check_omp_enabled(){
    #ifdef _OPENMP
        printf("OMP ENABLED\n");
        #pragma omp parallel
        {
            #pragma omp single
            printf("Executing OpenMP with %i threads!\n", omp_get_num_threads());
        }
    #else
        printf("WARNING! OMP DISABLED\n");
    #endif
}

int omp_get_num_threads_safe(){
    #ifdef _OPENMP
        return omp_get_num_threads();
    #else
        printf("WARNING! OMP DISABLED\n");
        return 1;
    #endif
}


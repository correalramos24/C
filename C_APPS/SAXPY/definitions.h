
#include <stdio.h>
#include <omp.h>

#ifdef DOUBLE_PREC
    #define WP double
#else
    #define WP float
#endif

void usage(){
    printf("Usage: saxpy.exe <SIZE>\n");
}

void initialize_arrays(const int N, WP *x, WP *y, WP *z){
    for (int i = 0; i < N; ++i) {
        x[i] = 1.0F;
        y[i] = 1.0F;
        z[i] = 0.0F;
    }
}
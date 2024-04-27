
#include <stdlib.h>
#include <math.h>
#include "io_helper.h"
#include "timing.h"
#include "random_init.h"
#include "my_exp.h"


int main(int argc, char const *argv[])
{
    //Argument checking
    if(argc != 2){
        printf("Usage: %s <number of elements>\n", argv[0]);
        return 1;
    }

    start_region("Allocate memory");
    long long N = atoi(argv[1]);
    if(N == -1) N = 50;
    double* x = (double *)malloc(N * sizeof(double));
    double* r = (double *)malloc(N * sizeof(double));
    
    if(N == -1){
        int aux = 0.01;
        for(int i = 0; i < N; ++i)
            x[i] = aux;
            aux+=0.1;
    }
    
    end_region();
    printf("Elements: %lld - Element size: %ld\n", N, sizeof(double));

    start_region("Initialize");
    fill_double_array(x, N, 0.0, 10.0, 33);
    end_region();

    start_region("Compute");
    for (size_t i = 0; i < N; i++)
    {
        #ifndef NEW
        r[i] = exp(x[i]);
        #else
        r[i] = my_exp(x[i]);
        #endif
    }
    double elap_time = end_region();

    start_region("Store results");
    #ifndef NEW
    write_double_array_into_file(r, "baseline.out", N, 'a');
    #else
    write_double_array_into_file(r, "new.out", N, 'a');
    #endif
    end_region();

    start_region("Free memory");
    free(x); free(r);
    end_region();

    return 0;
}

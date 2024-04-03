
#include <stdlib.h>
#include <math.h>
#include "io_helper.h"
#include "timing.h"
#include "random_init.h"

int main(int argc, char const *argv[])
{
    //Argument checking
    if(argc != 2){
        printf("Usage: <binary> <number of elements>\n");
        return 1;
    }

    start_region("Allocate memory");
    const long long N = atoi(argv[1]);
    double* x = (double *)malloc(N * sizeof(double));
    double* r = (double *)malloc(N * sizeof(double));
    end_region();
    printf("Elements: %lld - Element size: %ld\n", N, sizeof(double));

    start_region("Initialize");
    fill_double_array(x, N, 0.0, 10.0, 33);
    end_region();

    start_region("Compute");
    for (size_t i = 0; i < N; i++)
    {
        r[i] = exp(x[i]);
    }
    double elap_time = end_region();

    start_region("Store results");
    write_double_array_into_file(r, N, 'b');
    end_region();

    start_region("Free memory");
    free(x); free(r);
    end_region();

    return 0;
}

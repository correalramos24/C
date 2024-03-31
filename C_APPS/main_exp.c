
#include <stdlib.h>
#include <math.h>
#include "io_helper.h"
#include "timing.h"

int main(int argc, char const *argv[])
{
    start_region("Allocate memory");
    const long long N = 1024;
    float* x = (float *)malloc(N * sizeof(float));
    float* r = (float *)malloc(N * sizeof(float));
    end_region();
    printf("Elements: %lld - Element size: %ld\n", N, sizeof(float));

    start_region("Compute");
    for (size_t i = 0; i < N; i++)
    {
        r[i] = exp(x[i]);
    }
    double elap_time = end_region();

    start_region("Store results");
    write_array_into_file(r, N);
    end_region();

    start_region("Free memory");
    free(x); free(r);
    end_region();

    //I/O
    printf("EXP completed in %.8f s. ", elap_time);

    return 0;
}

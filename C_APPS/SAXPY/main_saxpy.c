#include <stdio.h>
#include <stdlib.h>
#include "timing.h"
#include <omp.h>
#include "definitions.h"
#include "omp_helper.h"


void saxpy(int N, WP a, const WP *x, const WP *y, WP * z) {
    int i;
    for (i = 0; i < N; ++i)
        z[i] = a * x[i] + y[i];
}

WP computeResult(const int N,const WP* z){
    WP ret = 0.0f;
    int i;
    for (i = 0; i < N; ++i) {
        ret += z[i];
    }
    return ret;
}


int main(int argc, char** argv) {
    
    check_omp_enabled();

    // 1. Parse arguments (size required)
    if(argc != 2) {
        usage();
        exit(1);
    }

    // 2. Allocate memory
    start_region("Allocate memory");
    const long long N = atoi(argv[1]);
    const WP a = 1.0F;
    WP *x = (WP *)malloc(N * sizeof(WP));
    WP *y = (WP *)malloc(N * sizeof(WP));
    WP *z = (WP *)malloc(N * sizeof(WP));
    printf("Elements: %lld - Element size: %ld\n", N, sizeof(WP));
    end_region();
    
    // 3. Initialize data
    start_region("initialize data");
    initialize_arrays(N, x, y ,z);
    end_region();

    // 4. Compute SAXPY
    start_region("SAXPY computation");
    saxpy(N, a, x, y, z);
    double elp_time = end_region();

    double flops = ((2 * N) / elp_time)/1000000;
    WP r = computeResult(N,z);

    // 5. Free memory
    start_region("Free memory");
    free(x);
    free(y);
    free(z);
    end_region();

    // 6. Report results
    printf("SAXPY completed in %.8f s. ", elp_time);
    printf("With result : %f\n",r);
    printf("> MFLOPS: %.2f\n", flops);
    return 0;
}
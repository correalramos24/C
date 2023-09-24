#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

void saxpy(int N, float a, const float *x, const float *y, float * z) {

    int i;
    for (i = 0; i < N; ++i) z[i] = a * x[i] + y[i];
}

float computeResult(const int N,const float* z){
    float ret = 0.0f;
    int i;
    for (i = 0; i < N; ++i) {
        ret += z[i];
    }
    return ret;
}

int main() {

    start_region("Allocate memory");
    const long long N = 1024;
    const float a = 1.0F;
    float *x = (float *)malloc(N * sizeof(float));
    float *y = (float *)malloc(N * sizeof(float));
    float *z = (float *)malloc(N * sizeof(float));
    end_region();

    printf("Elements: %lld - Element size: %ld\n", N, sizeof(float));

    start_region("initialize data");
    initialize_arrays(N, x, y ,z);
    end_region();

    start_region("SAXPY computation");
    saxpy(N, a, x, y, z);
    double elp_time = end_region();

    double flops = ((2 * N) / elp_time)/1000000;
    float r = computeResult(N,z);

    start_region("Free memory");
    free(x);
    free(y);
    free(z);
    end_region();

    //I/O
    printf("SAXPY completed in %.8f s. ", elp_time);
    printf("With result : %f\n",r);
    printf("> MFLOPS: %.2f\n", flops);
    return 0;
}
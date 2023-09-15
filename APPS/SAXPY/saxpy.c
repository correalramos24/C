#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


void saxpy(int N, float a, const float *x, const float *y, float * z) {

    int i;
    for (i = 0; i < N; ++i) z[i] = a * x[i] + y[i];
}

void initialize(const int N, float *x, float *y, float *z){
    int i;
    for (i = 0; i < N; ++i) {
        x[i] = 1.0F;
        y[i] = 1.0F;
        z[i] = 0.0F;
    }
}

float computeResult(const int N,const float* z){
    float ret = 0.0f;
    int i;
    for (i = 0; i < N; ++i) {
        ret += z[i];
    }
    return ret;
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
//    return tv.tv_sec + tv.tv_usec;
}



int main() {

    const long long N = 500*1024;
    float *x = (float *)malloc(N * sizeof(float));
    float *y = (float *)malloc(N * sizeof(float));
    float *z = (float *)malloc(N * sizeof(float));

    //Initialize data:
    printf("Elements: %lld\nElement size: %ld\n", N, sizeof(float));

    initialize(N, x, y ,z);
    double start_time = get_time();

    //sAXpY
    const float a = 1.0F;
    saxpy(N, a, x, y, z);
    float r = computeResult(N,z);
    double end_time = get_time();

    double elapsed_time = end_time - start_time;
    double flops = ((2 * N) / elapsed_time)/1000000;

    //I/O
    printf("SAXPY completed in %.8f s. ", elapsed_time);
    printf("With result : %f\n",r);
    printf("> MFLOPS: %.2f\n", flops);
    return 0;
}
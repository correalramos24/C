#include "timing.h"

void print_time(double elapsed, char* region){
    printf("%s -> %f\n", region, elapsed);
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}
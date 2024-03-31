#include "timing.h"

void print_time(double elapsed, char* region){
    printf("%s -> %f\n", region, elapsed);
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

bool log_enable = false;
bool in_a_region = false;
double start_region_bookmark;
char* current_region;

void start_region(char* name){
    current_region = name;
    if(log_enable) printf("LOG: Begin %s region\n", name);
    start_region_bookmark = get_time();
}
double end_region(){
    double elapsed = get_time() - start_region_bookmark;
    if(log_enable) printf("LOG: End %s region\n", current_region);
    printf("Region %s -> %.8f (s)\n", current_region, elapsed);
    return elapsed;
}
#include <sys/time.h>
#include <time.h>

typedef enum {false, true} bool;

void initialize_arrays(const int N, float *x, float *y, float *z){
    int i;
    for (i = 0; i < N; ++i) {
        x[i] = 1.0F;
        y[i] = 1.0F;
        z[i] = 0.0F;
    }
}

double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

// ==============================TIMING METHODS=================================
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



// ==============================TIMING METHODS=================================
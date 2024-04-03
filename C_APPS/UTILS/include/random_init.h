
#include <stdlib.h>

void fill_int_array(int data[], int N, int min, int max, int seed){
    srand(seed);

    for (int i = 0; i < N; ++i) {
        data[i] = min + rand() % (max - min + 1);
    }
}

void fill_float_array(float data[], int N, float min, float max, int seed){
    srand(seed);

    for (size_t i = 0; i < N; i++){
        data[i] = ((max-min) * ((float)rand() / RAND_MAX)) + min;
    }
}

void fill_double_array(double data[], int N, double min, double max, int seed){
    srand(seed);

    for (size_t i = 0; i < N; i++){
        data[i] = ((max-min) * ((double)rand() / RAND_MAX)) + min;
    }
}
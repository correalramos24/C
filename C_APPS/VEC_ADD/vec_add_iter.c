#include <stdlib.h>


int vec_add_iter(int* array, int N){
    int ret = 0;
    for (size_t i = 0; i < N; i++){
        ret += array[i];
    }
    return ret;
}
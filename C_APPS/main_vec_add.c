/**
 * VECTOR ADDITION
 * author: Victor Correal Ramos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "random_init.h"
#include <omp.h>
#include "omp_helper.h"

int vec_add_divide_and_conquer(int* array, int start, int end);
int vec_add_iter(int* array, int N);

int vec_add_divide_and_conquer(int* array, int start, int end){
    if(start == end)
        return array[start];
    else{
        const int middle = (start + end) / 2;
        int left_add = 0, right_add = 0;
        #pragma omp task
        left_add = vec_add_divide_and_conquer(array, start, middle);
        #pragma omp task
        right_add = vec_add_divide_and_conquer(array, middle+1, end);
        #pragma omp taskwait        
        return left_add + right_add;
    }
}

int vec_add_iter(int* array, int N){
    int ret = 0;
    for (size_t i = 0; i < N; i++){
        ret += array[i];
    }
    return ret;
}


int main(int argc, char const *argv[])
{
    check_omp_enabled();

    // Declare structures
    int* v;
    const int N = 1024*1024;
    
    // Init data
    v = (int*) malloc(N*sizeof(int));
    fill_array(v, N, 0, 100, 33);
    
    // Results
    int r1, r2, r3;
    r1 = vec_add_iter(v, N);
    printf("Completed vec_add_iter! Result %d\n", r1);

    #pragma omp parallel
    {
        #pragma omp single
        r3 = vec_add_divide_and_conquer(v, 0, N);
        #pragma omp single
        printf("Completed vec_add_d&c! Result %d\n", r3);
    }
    

    // free MEM
    free(v);

    return 0;
}

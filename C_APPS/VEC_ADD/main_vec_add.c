/**
 * VECTOR ADDITION
 * author: Victor Correal Ramos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#include "random_init.h"
#include "omp_helper.h"
#include "vec_add_alg.h"
#include "timing.h"


int main(int argc, char const *argv[])
{
    check_omp_enabled();
    // 0. Parse args (size required)
    if(argc != 2) {
        printf("Usage: %s <SIZE>\n", argv[0]);
        exit(1);
    }

    // 1. Allocate structures & init data
    const int N = atoi(argv[1]);
    int* v = (int*) malloc(N*sizeof(int));
    fill_int_array(v, N, 0, 100, 33);
    
    // 2. Run vec_add
    start_region("VEC_ADD computation");
    int results = vec_add(v, N);
    end_region();

    // 3.  free MEM
    free(v);

    return 0;
}

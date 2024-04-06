/**
 * 
 * ODD-EVEN ADDITION
 * Compute the number of odd and even numbers in a serie
 * author: Victor Correal Ramos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "random_init.h"
#include <omp.h>
#include "omp_helper.h"

int main(int argc, char *argv[]){
    check_omp_enabled();

    // Declare structures
    int* v;
    const int N = 1024*1024*1024;

    // Init data
    v = (int*) malloc(N*sizeof(int));
    fill_int_array(v, N, 0, 100, 33);

    int odd = 0, even = 0;
    int progress = 0;
    printf("PROGRESS:");
    for (size_t i = 0; i < N; i++)
    {
        if(v[i] % 2) odd++;
        if(! (v[i] % 2)) even++;

        if(i != 0 && i % (N/10) == 0){
            printf(" %i", progress);
            progress+=10;
        }
    }
    
    printf("\nRESULTS: ODD %i, EVEN %i\n", odd, even);
}
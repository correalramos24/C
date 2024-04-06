/**
 * 
 * Sieve of erathostenes
 * Search the N first prime numbers
 * author: Victor Correal Ramos
 * 
*/

#include <stdio.h>    
#include <stdlib.h>  
#include <stdbool.h>
#include "timing.h"

int main(int argc, char *argv[]){

    double t_init, t_end;

    #ifdef _IO
        printf("IO MODE ENABLE, may affect the performance!\n");
    #endif

    //Parse args:
    if(argc != 2){
        printf("USAGE: %s <num of max prime>\n", argv[0]);
        exit(1);
    }
    
    //INIT:
    start_region("INIT");
    int N = atoi(argv[1]);
    bool* prime = malloc(sizeof(bool)*(N+1));
    for(int i = 0; i <= N; ++i)
        prime[i] = true;
    
    t_end = get_time();
    end_region();

    //SIEVE: will be under sqrt(n) only
    start_region("SIEVE");
    for(int p = 2; p*p <= N; p++){
        if(prime[p]){
            //set false the multiples of p, under N:
            for(int i = p*p; i <= N; i+=p){
                prime[i] = false;
            }
        }
    }
    end_region();


    #if _IO
    //PRINT
    start_region("IO");
    int pretty=0;
    for(int p = 0; p < N; p++){
        if(prime[p])
        {
            printf("%i ", p);
            if(pretty % 4 == 0) printf("\n");
            pretty++;
        }
        
    }
    printf("\n");
    end_region();
    #endif
}
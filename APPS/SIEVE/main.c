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
        printf("USAGE: a.out <num of max prime>\n");
        printf("EXIT with code 1");
        exit(0);
    }
    
    //INIT:
    t_init = get_time();

    int N = atoi(argv[1]);
    bool* prime = malloc(sizeof(bool)*(N+1));
    for(int i = 0; i <= N; ++i)
        prime[i] = true;
    
    t_end = get_time();
    print_time(t_end-t_init, "INIT");

    //SIEVE: will be under sqrt(n) only
    t_init = get_time();
    for(int p = 2; p*p <= N; p++){
        if(prime[p]){
            //set false the multiples of p, under N:
            for(int i = p*p; i <= N; i+=p){
                prime[i] = false;
            }
        }
    }
    t_end = get_time();
    print_time(t_end-t_init, "SIEVE");


    #if _IO
    //PRINT
    t_init = get_time();
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
    t_end = get_time();
    print_time(t_end-t_init, "SIEVE");
    #endif
}
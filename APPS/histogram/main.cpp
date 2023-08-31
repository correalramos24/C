#include <bits/stdc++.h>
#include "rand_init.hh"

#define SEED_NUM 33

using namespace std;


int main(int argc, char const *argv[]){

    const int N = 33;
    const int MIN_VAL=0;
    const int MAX_VAL=50;

    int* data;
    int* hist;

    // Allocate data:
    data = (int*) malloc(sizeof(int)*N);
    hist = (int*) malloc(sizeof(int)*(1 + MAX_VAL - MIN_VAL));
    
    // Random initialize & memset for results:
    fill_array(data, N, MIN_VAL, MAX_VAL, SEED_NUM);
    memset(hist, 0, sizeof(int)*(1 + MAX_VAL - MIN_VAL));

    // Call to histogram computation
    for(int i = 0; i < N; ++i){
        hist[data[i]-MIN_VAL]++;
    }

    // Write the result
    for(int i = 0; i < N; ++i){
        cout << i << " " << hist[i] << endl;
    }

    // Free data
    free(data);
    free(hist);
    return 0;
}

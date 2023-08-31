#include <iostream>
#include <vector>
#include <omp.h>

#include "rand_init.hh"
#include "omp_helper.hh"


#define SEED_NUM 33
#define MIN_VAL 0
#define MAX_VAL 50

using namespace std;


int main(int argc, char const *argv[]){

    check_omp_enabled();

    const int N = 33;

    vector<int> data(N);
    vector<int> hist(1 + MAX_VAL - MIN_VAL, 0);

    // Random initialize input data
    fill_array(data.data(), data.size(), MIN_VAL, MAX_VAL, SEED_NUM);

    // Call to histogram computation
    for(int i = 0; i < N; ++i){
        hist[data[i]-MIN_VAL]++;
    }

    // Write the result
    for(int i = 0; i < N; ++i){
        cout << i << " " << hist[i] << endl;
    }

    return 0;
}

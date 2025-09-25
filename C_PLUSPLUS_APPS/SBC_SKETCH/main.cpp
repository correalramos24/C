#include "utils.hh"

#include <bits/stdc++.h>
#include <cmath>
#include <omp.h> 

using namespace std;


int main(int argc, char const *argv[]){
    // Define structures && initialize with random data
    int rows = 100, cols = 100;
    vector<vector<double>> zk_t, zk_u, zk_v;
    double zfac, ztransp;
    
    //=====================sbc_wave sketch=====================
    for (size_t i = 1; i <= rows; i++){
        for (size_t j = 1; j <= cols; j++){
            zk_t[i][j] = 33;
        }
    }
    
    #pragma omp barrier

    for (size_t i = 1; i <= rows; i++){
        for (size_t j = 1; j <= cols; j++){
            zk_u[i][j] = 0.5 * (zk_t[i][j] + zk_t[i + 1][j]);
            zk_v[i][j] = 0.5 * (zk_t[i][j] + zk_t[i][j + 1]);
        }
    }

    #pragma omp barrier
    #pragma omp master
    cout << "MPI COMMUNICATION HAPPENS HERE for  usd, vsd" << endl;

    return 0;
}

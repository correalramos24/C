#ifndef __MY_EXP__
#define __MY_EXP__

#include <math.h>

double my_exp(double x);
int my_factorial(int x);

double my_exp(double x){
    
    const int STEPS=10;
    double ret = 0.0;

    for(int n = 0; n < STEPS; ++n){
        ret += pow(x, n) / my_factorial(n);
    }
    return x;
}

int my_factorial(int x){
    long ret = 1;
    for (int i = 1; i <= x; ++i)
        ret *= i;
    return ret;
}

#endif
#include <omp.h>
#include <iostream>
//#include "extrae.h"

using namespace std;

double step;
static long num_steps = 1000000;

int main(){
    int i, id;
    double x, pi, sum = 0.0;

    step = 1.0/(double) num_steps;

    #pragma omp parallel private(x,i,id)
    {
        #pragma omp master
        {
            cout << omp_get_num_threads() << endl;
	    }
        id = omp_get_thread_num();

        for(i=id+1; i<= num_steps;i=i+omp_get_num_threads()){
            x = (i-0.5)*step;
            #pragma omp critical
            sum = sum + 4.0/(1.0+x*x);
            #pragma omp master
            cout << i << "/" << num_steps << endl;
        }
    }
    pi = sum * step;

    std::cout << pi << std::endl;

}

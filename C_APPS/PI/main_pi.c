#include <omp.h>


double step;
static long num_steps = 1000000;

int main(){
    int i, id, nt;
    double x, pi, sum = 0.0;

    step = 1.0/(double) num_steps;
    double sum_p = 0.0;
    for(i = id; i<= num_steps; i+=nt){
        x = (i - 0.5) * step;
        sum_p = sum_p + 4.0/(1.0+x*x);
    }

    sum += sum_p;
    pi = sum * step;
    
    printf("Result: %f", pi);
}

#include <omp.h>


double step;
static long num_steps = 1000000;

int main(){
    int i, id, nt;
    double x, pi, sum = 0.0;

    step = 1.0/(double) num_steps;

    #pragma omp parallel private(x,i,id)
    {
        id = omp_get_thread_num();
        nt = omp_get_num_threads();

        for(int i = id + 1; i<= num_steps; i += nt){
            x = (i - 0.5) * step;
            #pragma omp critical
            sum = sum + 4.0/(1.0+x*x);
        }
    }
    pi = sum * step;

    printf("Result: %f", pi);

}

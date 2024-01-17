#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 0;
    #pragma omp parallel reduction(+:x)
    {
        #pragma omp single
        {
            std::cout << "Num threads: " << omp_get_num_threads() << std::endl;
        }
        x += omp_get_thread_num();
    }
    
    std::cout << "Final result: " << x << std::endl;
    
    return 0;
}

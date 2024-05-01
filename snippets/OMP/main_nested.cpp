#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void printId(int& i){
    #pragma omp critical
    {
        cout    << "Hi from thread " << omp_get_thread_num() 
        << "/" << omp_get_num_threads() << " -> " << i << endl;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int i=1;
    #pragma omp parallel
    {
        #pragma omp parallel
        {
            //printId(i);
        }
    }
    return 0;
}

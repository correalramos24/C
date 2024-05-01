#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void printId(int& i){
    #pragma omp critical
    {
        cout    << "Hi from thread " << omp_get_thread_num() 
        << "/" << omp_get_num_threads() 
        << " @ " << omp_get_team_num() 
        << " -> " << i << endl;
        
        i++;
    }
}

int main(int argc, char const *argv[])
{
    int i=1;
    #pragma omp teams
    {
        //printId(i);
        //int x = omp_get_thread_num();
        #pragma omp parallel num_threads(3)
        {
            printId(i);
        }
    }
    return 0;
}

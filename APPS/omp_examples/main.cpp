#include <bits/stdc++.h>
#include <omp.h>
#include <unistd.h>     //sleep

unsigned int microseconds;


using namespace std;


int main(int argc, char const *argv[])
{
    int x = 43;
    #pragma omp parallel num_threads(4)
    {
            cout << "Hi ! I'm thread " << omp_get_thread_num() << endl;
            sleep(3);
    }
    
}

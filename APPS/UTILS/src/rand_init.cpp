
#include "rand_init.hh"
#include <cstdlib>   // Para funciones de generación de números aleatorios

using namespace std;


void fill_array(int data[], int N, int min, int max, int seed) {
    srand(seed);

    for (int i = 0; i < N; ++i) {
        data[i] = min + rand() % (max - min + 1);
    }
}
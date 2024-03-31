#ifndef __SORTING__
#define __SORTING__

#include <vector>
#include <iostream>

using namespace std;

template<class T>
class sorting {
private:
    static void i_mergesort(T* array, int const begin, int const end);
    static void merge(T* array, const size_t begin, const size_t mid, const size_t end);

public:
    static void mergeSort(vector<T>& in){
        mergeSort(in.data(), in.size());
    }
    static void mergeSort(T in[], const int size){
        i_mergesort(in, 0, size - 1);
    }
    static void bubbleSort(vector<T>& in){
        return;
    }
};

// Incluye el archivo de implementación
#include "sorting.cpp"

#endif
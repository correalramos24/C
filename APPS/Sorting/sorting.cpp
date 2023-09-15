#include "sorting.hh"

//=============================MERGE SORT IMPLEMENTATION=============================
template<class T>
void sorting<T>::i_mergesort(T* array, int const begin, int const end){
    if(begin >= end) return;
    
    const int mid = begin + (end - begin) / 2;
    i_mergesort(array, begin, mid);
    i_mergesort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

template<class T>
void sorting<T>::merge(T* array, const size_t begin, const size_t mid, const size_t end){
    const size_t sizeOne = mid - begin + 1;
    const size_t sizeTwo = end - mid;

    // Allocate and populate aux arrays:
    T* auxOne = new T[sizeOne];
    T* auxTwo = new T[sizeTwo];

    for(size_t i = 0; i < sizeOne; ++i) 
        auxOne[i] = array[begin+i];
    for(size_t i = 0; i < sizeTwo; ++i)
        auxTwo[i] = array[mid + 1 + i];

    // Merge one & two into T:
    size_t iOne = 0, iTwo = 0, iSorted = 0;

    while(iOne < sizeOne and iTwo < sizeTwo){
        if(auxOne[iOne] <= auxTwo[iTwo])
            array[iSorted++] = auxOne[iOne++];
        else
            array[iSorted++] = auxTwo[iTwo++];
    }

    // Copy the remainig elements of aux
    for(size_t i = iOne; i < sizeOne; ++i) 
        array[iSorted++] = auxOne[i];

    for(size_t i = iOne; i < sizeOne; ++i) 
        array[iSorted++] = auxTwo[i];
    
    // Free aux arrays:
    delete[] auxOne;
    delete[] auxTwo;
    
}
//=============================MERGE SORT IMPLEMENTATION=============================

#ifndef __VEC_ADD_VERSION__
#define __VEC_ADD_VERSION__


int vec_add(int* array, int N);

#ifdef REC_VERSION
    int vec_add_divide_and_conquer(int* array, int start, int end);        
#else    
    int vec_add_iter(int* array, int N);
#endif




int vec_add(int* array, int N){
    #ifdef REC_VERSION
        printf("Using recursive approach...\n");
        return vec_add_divide_and_conquer(array, 0, N-1);
    #else
        return vec_add_iter(array, N);
    #endif
}


#endif
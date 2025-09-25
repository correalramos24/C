
#define MAX_DEPTH 5

int vec_add_divide_and_conquer(int* array, int start, int end, int depth){
    if(start == end)
        return array[start];
    else{
        const int middle = (start + end) / 2;
        int left_add, right_add;

        #pragma omp task shared(left_add)
        left_add = vec_add_divide_and_conquer(array, start, middle, depth+1);
        #pragma omp task shared(right_add)        
        right_add = vec_add_divide_and_conquer(array, middle+1, end, depth+1);
        #pragma omp taskwait
        
        return left_add + right_add;
    }
}
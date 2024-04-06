int vec_add_divide_and_conquer(int* array, int start, int end){
    if(start == end)
        return array[start];
    else{
        const int middle = (start + end) / 2;
        int left_add = 0, right_add = 0;
        #pragma omp task
        left_add = vec_add_divide_and_conquer(array, start, middle);
        #pragma omp task
        right_add = vec_add_divide_and_conquer(array, middle+1, end);
        #pragma omp taskwait        
        return left_add + right_add;
    }
}
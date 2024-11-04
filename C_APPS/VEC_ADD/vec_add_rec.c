
#define MAX_DEPTH 5

int vec_add_divide_and_conquer(int* array, int start, int end, int depth){
    if(start == end)
        return array[start];
    else{
        const int middle = (start + end) / 2;
        int left_add = vec_add_divide_and_conquer(array, start, middle, depth+1);
        int right_add = vec_add_divide_and_conquer(array, middle+1, end, depth+1);
        return left_add + right_add;
    }
}
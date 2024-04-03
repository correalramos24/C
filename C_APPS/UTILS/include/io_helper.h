#ifndef __IO_HELPER__
#define __IO_HELPER__

#include <stdio.h>
#include <stdlib.h>

// Header only utils for IO utilities

void write_float_array_into_file(float* array, const int N, const char m){
    // Open
    FILE *file = fopen("output.bin", "w");
    if(file == NULL) {
        printf("fopen: error"); 
        exit(0);
    }
    // Write
    fwrite(array, sizeof(float), N, file);

    // Close
    fclose(file);

    return;
}

void write_double_array_into_file(double* array, const int N, const char m){
    // Open
    FILE *file = fopen("output.bin", "w");
    if(file == NULL) {
        printf("fopen: error"); 
        exit(0);
    }
    // Write
    fwrite(array, sizeof(double), N, file);

    // Close
    fclose(file);

    return;
}

#endif
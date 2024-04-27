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

void write_double_array_into_file(  double* array, 
                                    const char* fName,
                                    const int N, 
                                    const char m)
{
    // Open
    FILE *file = fopen(fName, "w");
    if(file == NULL) {
        printf("fopen: error"); 
        exit(0);
    }
    // Write
    if(m == 'b') {
        fwrite(array, sizeof(double), N, file);
    }
    else if(m == 'a'){
        for (int i = 0; i < N; i++) {
            fprintf(file, "%lf\n", array[i]);
        }
    }
    else{
        printf("Invalid mode : %c ", m);
        exit(1);
    }

    // Close
    fclose(file);

    return;
}

#endif
#include "io_helper.h"


void write_array_into_file(float* array, const int N){
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
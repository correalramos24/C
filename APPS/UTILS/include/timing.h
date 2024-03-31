#ifndef __TIMING__
#define __TIMING__

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

double get_time();

void print_time(double elapsed, char* region);

// Timing v2


void start_region(char* name);

double end_region();

#endif
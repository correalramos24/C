#ifndef __TIMING__
#define __TIMING__

#include <sys/time.h>
#include <time.h>
#include <stdio.h>

double get_time();

void print_time(double elapsed, char* region);

#endif
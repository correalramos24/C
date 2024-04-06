
UTILS = ../UTILS/include
SRC =  main_saxpy.c 
HDR = definitions.h $(UTILS)/*.h

CC = gcc
CFLAGS = -I ../UTILS/include

saxpy_targets: saxpy.exe saxpy_double.exe saxpy_double_omp.exe

saxpy.exe: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@

saxpy_double.exe: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -D DOUBLE_PREC

saxpy_omp.exe: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -fopenmp

saxpy_double_omp.exe: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -D DOUBLE_PREC -fopenmp

clean_saxpy:
	rm -rdf *.exe *.o
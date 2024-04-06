UTILS = ../UTILS/include
SRC =  main_sieve.c 
HDR = $(UTILS)/timing.h

CC = gcc
CFLAGS = -I ../UTILS/include

sieve_targets: sieve.exe sieve_omp.exe sieve_io.exe sieve_io_omp.exe

sieve.exe: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@

sieve_io.exe:  $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -D_IO=1

sieve_omp.exe: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -fopenmp
	
sieve_io_omp.exe: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -fopenmp -D_IO=1


.PHONY:clean
clean:
	rm -rdf *.exe *.o
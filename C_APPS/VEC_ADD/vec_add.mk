
UTILS = ../UTILS/include
SRC = main_vec_add.c 
HDR = vec_add_alg.h $(UTILS)/*.h

CC = gcc
CFLAGS = -I ../UTILS/include

vec_add_targets: vec_add.exe vec_add_rec.exe vec_add_omp.exe vec_add_rec_omp.exe


vec_add.exe: $(SRC) $(HDR) vec_add_iter.c
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@

vec_add_rec.exe: $(SRC) $(HDR) vec_add_rec.c
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -D REC_VERSION

vec_add_omp.exe: $(SRC) $(HDR) vec_add_iter.c
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -fopenmp

vec_add_rec_omp.exe: $(SRC) $(HDR) vec_add_rec.c
	$(CC) $(CFLAGS) $(filter %.c, $^) -o $@ -D REC_VERSION -fopenmp

clean_vec_add:
	@echo $(HDR)
	rm -rdf *.exe *.o
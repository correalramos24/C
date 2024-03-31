
CC = gcc
CFLAGS= -I UTILS/include

all: saxpy.exe exp.exe odd_even.exe sieve.exe sieve_io.exe vec_add.exe

.PHONY: clean

saxpy.exe: main_saxpy.o timing.o
	$(CC) $(CFLAGS) $^ -o $@

exp.exe: main_exp.o timing.o io_helper.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

odd_even.exe: main_odd_even.o random_init.o timing.o
	$(CC) $(CFLAGS) $^ -o $@

sieve.exe: main_sieve.o timing.o
	$(CC) $(CFLAGS) $^ -o $@

sieve_io.exe: main_sieve.c timing.o
	$(CC) $(CFLAGS) $^ -o $@ -D_IO=1

vec_add.exe: main_vec_add.o random_init.o
	$(CC) $(CFLAGS) $^ -o $@

# UTILS DEFINITIONS TO BE MOVED
timing.o: UTILS/include/timing.h UTILS/src/timing.c
	$(CC) $(CFLAGS) -c UTILS/src/timing.c -o $@

io_helper.o: UTILS/include/io_helper.h UTILS/src/io_helper.c
	$(CC) $(CFLAGS) -c UTILS/src/io_helper.c -o $@

random_init.o: UTILS/include/random_init.h UTILS/src/random_init.c
	$(CC) $(CFLAGS) -c UTILS/src/random_init.c -o $@
	
clean:
	rm -rdf *.exe *.o

run:
	@echo "WIP"
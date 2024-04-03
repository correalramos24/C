
CC = gcc
CFLAGS = -I UTILS/include
BINDIR = BIN
OBJDIR = .OBJ

$(shell mkdir -p $(BINDIR) $(OBJDIR))

all: $(BINDIR)/saxpy.exe $(BINDIR)/exp.exe $(BINDIR)/odd_even.exe \
	$(BINDIR)/sieve.exe $(BINDIR)/sieve_io.exe $(BINDIR)/vec_add.exe

.PHONY: clean

$(OBJDIR)/main_%.o: main_%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(BINDIR)/saxpy.exe: $(OBJDIR)/main_saxpy.o
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)/exp.exe: $(OBJDIR)/main_exp.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(BINDIR)/odd_even.exe: $(OBJDIR)/main_odd_even.o
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)/sieve.exe: $(OBJDIR)/main_sieve.o 
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)/sieve_io.exe: $(OBJDIR)/main_sieve.o
	$(CC) $(CFLAGS) $^ -o $@ -D_IO=1

$(BINDIR)/vec_add.exe: $(OBJDIR)/main_vec_add.o
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rdf *.exe *.o
	rm -rdf $(BINDIR) $(OBJDIR)
pronto:
	echo $(UTILS_SRC)

run:
	@echo "WIP"
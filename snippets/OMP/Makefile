
CCX = g++
CXXFLAGS := -O3 -fopenmp
debug_% : CXXFLAGS=-O0 -g -fopenmp

OUTDIR = bin
TARGETS=main_nested main_teams debug_main_nested debug_main_teams

all: $(TARGETS)

debug_%: %.cpp bin_dir
	$(CCX) $(CXXFLAGS) $(subst debug_,,$@).cpp -o $(OUTDIR)/$@

% : %.cpp bin_dir
	$(CCX) $(CXXFLAGS) $@.cpp -o $(OUTDIR)/$@

bin_dir:
	mkdir -p bin

clean:
	rm -fdr main_nested main_teams $(OUTDIR)

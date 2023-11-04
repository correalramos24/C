
- [OpenMP](#openmp)
  - [API calls](#api-calls)
  - [Basic directives](#basic-directives)
    - [Parallel region definition](#parallel-region-definition)
    - [Synchronitzation mechanism](#synchronitzation-mechanism)
  - [Worksharing directives](#worksharing-directives)
  - [Task paralelism](#task-paralelism)


# OpenMP

## API calls

```c++
//Thread ids
int omp_get_thread_num();   // Id [0, N/1]
int omp_get_num_threads();  // N 
int omp_get_max_threads();
void omp_set_num_threads(int);

// Timing
double start = omp_get_wtime(); 
double end = omp_get_wtime(); 
```


## Basic directives

### Parallel region definition

parallel
```c++
#pragma omp parallel [clauses]
```

### Synchronitzation mechanism

## Worksharing directives

## Task paralelism


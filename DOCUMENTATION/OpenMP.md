
- [OpenMP](#openmp)
  - [Bascic API calls](#bascic-api-calls)
  - [Definitions](#definitions)
    - [Data-sharing](#data-sharing)
  - [Synchronization directives](#synchronization-directives)
  - [Basic directives - Constructors](#basic-directives---constructors)
    - [Parallel region](#parallel-region)
    - [Explicit tasks definition](#explicit-tasks-definition)
      - [Task dependencies](#task-dependencies)
      - [Task synchronization](#task-synchronization)
  - [Worksharing directives](#worksharing-directives)
    - [Section and Single worksharing](#section-and-single-worksharing)
    - [Explicit task worksharing](#explicit-task-worksharing)
    - [Implicit task worksharing](#implicit-task-worksharing)


# OpenMP

Compiler directives framework for multithreading with C, C++ and Fortran.

## Bascic API calls

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

## Definitions

### Data-sharing

There are different kinds of variables in OpenMP, depending the behavior that we require:

1. Shared variable: All references within a task to this kind of variable points to the original variable. Synchronization by the programmer is required to avoid data-race.
2. Private variable: Each thread has a private (local) variable.
3. Firstprivate variable: Same as private, but initialized with the original item when the constructor is found.

By default, OpenMP sets all the variables referenced inside a constructor as shared. `default(none)` requires that each variable explicitly determine in a data-sharing clause.

## Synchronization directives

## Basic directives - Constructors

### Parallel region

This constructor create a new <u>team</u> of threads to execute the block. There is a implicit <u>barrier</u> at the end of the parallel block.

```c++
#pragma omp parallel [clause[ [,] clause] ... ]
{
  //Code block to be executed by each thread
} 
// Implicit barrier
```

* `num_threads (num_threads)`: Set the number of threads of the region 
* `if (scalar-integer-expr)`: If the condition evaluates to false, the parallel region is not created.
* `proc_bind(master | close | spread)`: Thread affinity clause
* `default({shared | private | firstprivate})`: Default data-sharing 
* `{shared | private | firstprivate} (list)`: Data-sharing clauses
*  `reduction(op: var)`: Reduction clause.
* Data copying clause `copyin(list)`: Mechanism to copy from the master thread to the thread private space (allow array and non-array variables).

### Explicit tasks definition

Each thread that encounters this constructor will generate an explicit task, that can be directly executed or defer its execution for the future, that will be executed by any thread in the <u>team</u>. 

The task will execute the code block with the data environment defined by the data-sharing clauses on the directive (by default, variables are captured as firstprivate).

Completion of the tasks is only guaranteed using <u>task synchronization</u> constructs.

````c
#pragma omp task [clause[ [,] clause] ... ]
{
    // Code block
}
````

* `final(bool exp)`: Marks this an they successor (if they are) as final, meaning that the task is created but executed immediately in the  . With the API call `omp_in_final()` the programmer can get the final status.
* `mergeable`: Directly execute the code block, don't generate the task.
* `private | firsprivate | shared (list)`: Data-sharing clauses
* `depend`: See task dependencies definitions

#### Task dependencies

#### Task synchronization


## Worksharing directives

Distribute the execution of the region among the threads of a <u>team</u>.


### Section and Single worksharing
Just one thread will execute this blocks

### Explicit task worksharing

### Implicit task worksharing



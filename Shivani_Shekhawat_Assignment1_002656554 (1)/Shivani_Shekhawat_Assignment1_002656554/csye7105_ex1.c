/* CSYE7105 HW1 Sol1*/
/* SHIVANI SHEKHAWAT 002656554*/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nthreads, tid, procs, maxt, inpar, dynamic, nested;

/* Start parallel region */
#pragma omp parallel private(nthreads, tid)
  {

  /* Obtaining thread number*/
  tid = omp_get_thread__num();

  /* Only master thread does this */
  if (tid == 0) 
    {
    printf("Thread %d getting environment info...\n", tid);

    /* Get environment information */	
    procs = omp_get_num_procs(); // get the number of processors available to the device 
    nthreads = omp_get_num_threads(); // get the number of threads
    maxt = omp_get_max_threads(); // get maximum threads available
    inpar = omp_in_parallel(); // is it in parallel?
    dynamic = omp_get_dynamic(); // Dynamic threads enabled?
    nested = omp_get_nested(); // Nested parallelism supported?


    /* Print environment information */
    printf("Number of processors = %d\n", procs);
    printf("Number of threads = %d\n", nthreads);
    printf("Max threads = %d\n", maxt);
    printf("In parallel? = %d\n", inpar);
    printf("Dynamic threads enabled? = %d\n", dynamic);
    printf("Nested parallelism supported? = %d\n", nested);

    }

  }  /* Done */

}

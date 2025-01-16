/* CSYE7105 HW1 Sol2*/
/* SHIVANI SHEKHAWAT 002656554*/

#include <omp.h>
#define N 1000
#define N_THREADS 4

main () 
{
int tid, i, chunk;
double a[N], b[N], c[N];
		  	  
omp_set_num_threads(N_THREADS)
chunk = N/N_THREADS;

/* Please complete the data scope in the OpenMP parallel directive line: 8 points */
/* Use clause to define the number of threads using N_THREADS: 4 points 
   and put this in the second line: 2 points */
#pragma omp parallel shared(a, b, c, chunk)
private(tid, i) 
  {
  tid = omp_get_thread_num(); // get the thread number, 2 points
  for (i = tid * chunk; i < (tid+1) * chunk; i++)
    {
    c[i] = a[i] + b[i];
    }

  }  /* end of parallel section */   

}
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define n 10000
int main()
{
  omp_lock_t lock;
  omp_init_lock(&lock);
  int i,time1,time2,tab [n];
  double s=0;
  for(i=0;i<=n;i++)
	tab[i]=i;
  time1=omp_get_wtime();  
  #pragma omp parallel sections num_threads(2)
  {
    #pragma omp section
	for(int i=0;i<n/2;i++)
	{ 
	omp_set_lock(&lock);
	s=s+tab[i];	
	omp_unset_lock(&lock);
    }
   #pragma omp section
	for(int i=n/2;i<n;i++)
	{ 
	
	omp_set_lock(&lock);
	s=s+tab[i];	
	omp_unset_lock(&lock);
    }
  }	
  time2=omp_get_wtime();
  printf("Sum=%f execution time=%d\n",s,(time2-time1));
  omp_destroy_lock(&lock);
  return 0;
}
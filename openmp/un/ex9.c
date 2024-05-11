#include<stdio.h>
#include<omp.h>

#define n 50000
void main(){
	long t_init , t_end;
	long tab[n];
	int size;
	double s = 0 ;
	t_init = omp_get_wtime();
	for(int i = 0 ; i < n ; i++){
		tab[i] = i ;
		}
	#pragma omp parallel
	{
	size = omp_get_num_threads();
	#pragma omp for reduction(+:s) 
	for(int i = 0 ; i < n ; i++)
	{
//		#pragma omp atomic
		s = s + tab[i];
		
	}
	}
		t_end = omp_get_wtime();
	printf("exec time = %ld size = %d sum = %f\n",(t_end - t_init) , size , s );
	
}

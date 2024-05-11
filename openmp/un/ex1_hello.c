#include<stdio.h>
#include<omp.h>

void main(){
/*
	#pragma omp parallel 
	// parallel region
	{
		int tid = omp_get_thread_num();
		int size = omp_get_num_threads();
		printf("i am thread %d in a thread team of size %d\n",tid,size);
	}
	printf("end of parallel region 1");

	int a = 100 ;
	#pragma omp parallel firstprivate(a)
	{
		int tid = omp_get_thread_num();
		a += tid;
		printf("thread %d , a = %d\n",tid,a);
	}
	printf("a = %d\n", a);


	#define n 1001
	#pragma omp parallel if(n > 10)
	{
		omp_set_num_threads(2);
		int status = omp_in_parallel();
		printf("hello world with status = %d\n",status);
	}
	#pragma omp parallel if(n>1000)
	omp_set_num_threads(10);
	{
		int status = omp_in_parallel();
		printf("hello khaled with status = %d\n",status);
	}

	long t_ref , t_end;
	int size;
	#pragma omp parallel
	{
		size = omp_get_num_threads();
		t_ref = omp_get_wtime();
		#pragma omp for
		for(int i = 0  ; i < 100000;i++)
			for(int j = 0 ; j < 10000 ; j++)
		t_end = omp_get_wtime();
	}

	printf("execution time = %ld with %d thread\n", (t_end-t_ref) , size);


	int tid ;
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		#pragma omp for
		for(int i = 0 ; i < 8 ; i++)
			printf("thread num %d print %d\n",tid,i);
	}
*/
}

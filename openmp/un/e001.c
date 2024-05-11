#include<stdio.h>
#include<omp.h>

int main(){
/*
	#pragma omp parallel
	{
	printf("hello\n");
	}
	
	omp_set_num_threads(8);
	#pragma omp parallel
	{
	printf("8 thread\n");
	}
	
	omp_set_num_threads(3);
	int id;
	#pragma omp parallel
	{
	id = omp_get_thread_num();
	printf("thread %d : hello \n", id);
	}
	#pragma omp parallel
	{
	printf("1\n");
	printf("2\n");
	printf("3\n");
	} 
	
	int i = omp_get_num_procs();
	printf("i = %d " , i);

	int x = 90 ;
	#pragma omp parallel
	{
		int ID ;
		ID = omp_get_thread_num();
		printf("x = %d , inside thread no ID = %d \n" , x , ID);
	}
	printf("x after parallel region = %d \n",x);
	return 0;


	// serial region 1
	printf("inside serial region 1 ...\n");
	// parallel region 1
	#pragma omp parallel
	printf("inside parallel region 1 ...\n");
	// join
	// serial region 
	printf("inside serial region 2 ...\n");
	// parallel region 2
	#pragma omp parallel
	{
		printf("inside parallel region 2 , statement 1 ..\n");
		printf("inside parallel region 2 , statement 2 ..\n");
		
	}	
	// join 
	// serial region 3
	printf("serial region 3 ");
*/
	int x = 10 ;
	int i = 1 ;
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		do{
			int y = 1;
			printf("thread %d with x = %d \n",ID,x);
			x += y ;
			i++;
			y++;
			}while(i<=10);
		printf("x = %d\n",x);
	}	
}

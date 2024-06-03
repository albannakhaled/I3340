#include <stdio.h>
#include <omp.h>
#define n 100000
int main() {
long t_ref,t_end;
long A[n],B[n];
int size;  //A----> B[i]=1+2+3.......+A[i]
for(int i=0;i<n;i++)
{
	A[i]=n+i; 
	B[i]=0;
}
#pragma omp parallel
{
    t_ref= omp_get_wtime();//initial time
	size=omp_get_num_threads();
	#pragma omp for  
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<A[i];j++)
			{
				B[i]+=j;
			}
		}
    t_end= omp_get_wtime();//final time
}
    printf("Execution time=%d size=%d\n", (t_end-t_ref),size);
    return 0;
}
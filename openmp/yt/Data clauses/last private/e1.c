#include <stdio.h>
#include <stdlib.h>
#include <omp.h>  
int main(void){
int i,x=44,tid;

#pragma omp parallel for lastprivate(x)
for(i=0;i<=10;i++){
	x=i;
	tid=omp_get_thread_num();
	printf("Thread number: %d x: %d\n",tid,x);
}
printf("x is %d\n", x);
return 0; 
}
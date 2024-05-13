// Write a C program that compute the sum of elements in a table.
// Parallelize that program with OpenMP.

#include<stdio.h>
#include<omp.h>
#define N 10

void main(){
    int sum = 0 ;
    int tab[N];
    for(int i = 0 ; i < N ; i++){
        tab[i] = (i*3);
    }
    #pragma omp parallel
    {
        #pragma omp for 
        for (int i = 0; i < N; i++)
        {
            sum += tab[i];
        }
    }
    printf("sum = %d\n",sum);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <omp.h>
// #define n 500000
// int main()
// {
//   int i,time1,time2,tab [n];
//   double s=0;
//   for(i=0;i<=n;i++)
// 	tab[i]=i;
//   time1=omp_get_wtime();  
//   #pragma omp parallel for private(i) 
//   for(int i=0;i<n;i++)
//   { 
// 	s=s+tab[i];	
//   }	
//   time2=omp_get_wtime();
//   printf("Sum=%f execution time=%d\n",s,(time2-time1));
//   return 0;
// }
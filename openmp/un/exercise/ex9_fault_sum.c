#include <stdio.h>
#include <omp.h>
#define N 10

int main() {
    int tab[N];
    int i;
    int sum = 0;
    int time1,time2;

    #pragma omp parallel for shared(tab)
    for (i = 0; i < N; i++) {
        tab[i] = i;
    }

    // Calculate the sum in parallel using reduction
    time1=omp_get_wtime();
    #pragma omp parallel for num_threads(4)
    for (i = 0; i < N; i++) {
        #pragma omp atomic
        sum += tab[i];
        for(int j = 0 ; j < 1000000000;j++);
    }
    time2=omp_get_wtime();
    printf("sum = %d\n", sum);
    printf("execution time=%d\n",(time2-time1));
    return 0;
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
//   #pragma omp atomic
//   	s=s+tab[i];	
//   }	
//   time2=omp_get_wtime();
//   printf("Sum=%f execution time=%d\n",s,(time2-time1));
//   return 0;
// }
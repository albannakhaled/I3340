#include <omp.h>
#include <stdio.h>

#define N 1000000

int main() {
    int tid ;
    #pragma omp parallel
    {
    #pragma omp for
    for(int i = 1 ; i < 10 ; i++){
        printf("thread num %d print %d\n",omp_get_thread_num(),i);
    }
    }
}

// #pragma omp for without #pragma omp parallel , share the iteration of one thread 
// #pragma omp parallel for , share the iteration with all available thread

// 2 ways to write parallel for region
// #pragma omp parallel for          or          #pragma omp parallel
//                                               #pragma omp for
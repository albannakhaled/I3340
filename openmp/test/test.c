#include <omp.h>
#include <stdio.h>

#define N 1000000

int main() {
    int tid ;
    
    #pragma omp for
    for(int i = 1 ; i < 10 ; i++){
        printf("thread num %d print %d\n",omp_get_thread_num(),i);
    }
}
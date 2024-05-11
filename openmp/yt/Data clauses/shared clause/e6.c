#include<stdio.h>
#include<omp.h>

void set_thread_nums() {
    int n_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &n_threads);
    omp_set_num_threads(n_threads);
}
void main(){
    set_thread_nums();
        int a = 10 ;
    #pragma omp parallel shared(a)
    {
        int tid = omp_get_thread_num();
        a = a + tid;
        printf("thread %d , a = %d\n",tid,a);
    }
    printf("a in out region = %d\n",a);
}
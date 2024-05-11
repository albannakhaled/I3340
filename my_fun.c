#include<stdio.h>
#include <my_fun.h>

void set_thread_nums() {
    int n_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &n_threads);
    omp_set_num_threads(n_threads);
}
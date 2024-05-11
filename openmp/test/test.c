#include <omp.h>
#include <stdio.h>

#define N 1000000

int main() {
    int arr[N];
    long t_start1, t_end1,t_start2, t_end2;
    // Initialize the array
    t_start1 = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        arr[i] = i;
        for(int j = 0; j < 10000;j++);
    }
    t_end1 = omp_get_wtime();
    printf("Time taken to initialize the array: %ld\n", t_end1 - t_start1);
    // Parallelize the loop using #pragma omp for
    t_start2 = omp_get_wtime();
    #pragma omp parallel for

    for (int i = 0; i < N; i++) {
        arr[i] = arr[i] * 2; // Perform some computation on each element
        for(int j = 0; j < 10000;j++);

    }
    t_end2 = omp_get_wtime();

    // Print the first few elements of the array
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken to perform the computation2: %ld\n", t_end2 - t_start2);

    return 0;
}
#include <omp.h>
#include <stdio.h>

#define N 1000000

int main() {
    int i;
    int arr[N];
    int sum = 0; // Shared variable

    // Initialize the array
    for (i = 0; i < N; i++) {
        arr[i] = i;
    }

    // Parallelize the loop using #pragma omp for
    #pragma omp parallel for private(i) reduction(+:sum)
    for (i = 0; i < N; i++) {
        int temp = arr[i]; // Private variable
        sum += temp;       // Update the shared sum
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
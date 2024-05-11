#include <omp.h>
#include <stdio.h>

#define SIZE 100

int main() {
    int array[SIZE];
    int sum = 0;

    // Initialize array
    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    // Parallel summation of array elements
    #pragma omp for 
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    printf("Sum: %d\n", sum);

    return 0;
}

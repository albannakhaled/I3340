#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 1000000

int main() {
    long t_init , t_end;
    int arr[SIZE];
    int min_value = INT_MAX; // Initialize min_value to the maximum possible integer value

    // Initialize the array with some values
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000000; // Random values between 0 and 999999
    }

    // Find the minimum value in parallel
    t_init = omp_get_wtime();
    #pragma omp parallel for shared(arr) reduction(min:min_value)
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    t_end = omp_get_wtime();

    printf("Minimum value in the array: %d\n", min_value);
    printf("Time: %f\n", (double)(t_end - t_init));
    return 0;
}


/*
Here's how the program works:

We define a constant SIZE of 1000000 to represent the size of the array.
We declare an integer array arr of size SIZE and initialize it with random values between 0 and 999999 using the rand() function.
We declare a shared variable min_value and initialize it with the maximum possible integer value (INT_MAX) from the limits.h header file.
We use the #pragma omp parallel for directive to create a team of threads, and each thread executes a portion of the loop iterations.
Inside the parallel loop, each thread checks if the value in the array at its current iteration is smaller than the current min_value. If it is, the thread updates min_value with the new smaller value.
The reduction(min:min_value) clause ensures that the final value of min_value is the minimum of all the values computed by each thread.
After the parallel loop completes, the min_value variable will hold the minimum value in the arr array.
We print the minimum value using printf.

Note that in this example, we don't need to use a critical section or any other synchronization mechanism because the reduction(min:min_value) clause ensures that the updates to min_value are performed correctly and without race conditions.
*/
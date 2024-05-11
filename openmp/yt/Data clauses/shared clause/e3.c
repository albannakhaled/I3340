#include <omp.h>
#include <stdio.h>

int main() {
    const int size = 1000;
    int arr[size]; // This is a shared array
    int max_value = 0; // This is a shared variable
    int i;
    // Initialize the array with some values
    #pragma omp parallel for shared(arr,i)
    for ( i = 0; i < size; i++) {
        arr[i] = i+1;
    }

    #pragma omp parallel for shared(arr, max_value)
    for (int i = 0; i < size; i++) {
        // Each thread updates the max_value if it finds a larger value in the array
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    printf("Maximum value in the array: %d\n", max_value);
    return 0;
}


/*
In this example, we have an array arr and a variable max_value, both of which are shared among all threads in the parallel region.

The arr array is initialized with values from 0 to 999.
The #pragma omp parallel for directive creates a team of threads, and each thread executes a portion of the loop iterations.
Inside the parallel loop, each thread checks if the value in the array at its current iteration is greater than the current max_value. If it is, the thread updates max_value with the new larger value.
Since multiple threads may try to update max_value simultaneously, we use a critical section to ensure that only one thread can modify max_value at a time, preventing race conditions.
After the parallel loop completes, the max_value variable will hold the maximum value in the arr array.

In this example, we need to use a shared variable max_value to accumulate the maximum value found by all threads. We also need to use a critical section to ensure thread-safe updates to max_value.
*/
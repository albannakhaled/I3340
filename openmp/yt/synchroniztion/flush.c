#include <stdio.h>
#include <omp.h>

int main() {
    int x = 0;

    #pragma omp parallel num_threads(2)
    {   
        if (omp_get_thread_num() == 0) {
            x = 42; // Thread 0 writes to shared variable x
            #pragma omp flush(x) // Ensure the write to x is visible to all threads
        } else {
            #pragma omp flush(x) // Ensure that the value of x is consistent across threads
            printf("Value of x seen by thread 1: %d\n", x); // Thread 1 reads the value of x
        }
    }

    return 0;
}

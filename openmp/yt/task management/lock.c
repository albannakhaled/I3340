#include <stdio.h>
#include <omp.h>

int shared_variable = 0;
omp_lock_t lock;

int main() {
    // Initialize the lock
    omp_init_lock(&lock);

    // Parallel region
    #pragma omp parallel num_threads(4)
    {
        // Each thread increments the shared variable 100 times
        for (int i = 0; i < 100; i++) {
            // Acquire the lock before accessing the shared variable
            omp_set_lock(&lock);
            shared_variable++;
            // Release the lock after modifying the shared variable
            omp_unset_lock(&lock);
        }
    }

    // Destroy the lock
    omp_destroy_lock(&lock);

    printf("Final value of shared_variable: %d\n", shared_variable);

    return 0;
}

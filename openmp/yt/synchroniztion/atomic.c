#include <stdio.h>
#include <omp.h>

int main() {
    int shared_variable = 0;

    #pragma omp parallel num_threads(4)
    {
        // Each thread increments the shared variable 100 times
        for (int i = 0; i < 100; i++) {
            #pragma omp atomic
            shared_variable++;
        }
    }

    printf("Final value of shared_variable: %d\n", shared_variable);

    return 0;
}

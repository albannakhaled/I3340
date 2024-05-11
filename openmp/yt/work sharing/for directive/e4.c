#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SAMPLES 1000000

int main() {
    int inside_circle = 0;

    // Initialize random number generator
    srand(time(NULL));

    // Parallel Monte Carlo simulation for estimating pi
    #pragma omp parallel for reduction(+:inside_circle)
    for (int i = 0; i < NUM_SAMPLES; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            inside_circle++;
        }
    }

    double pi_estimate = 4.0 * inside_circle / NUM_SAMPLES;
    printf("Estimated value of pi: %f\n", pi_estimate);

    return 0;
}

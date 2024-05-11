#include <omp.h>
#include <stdio.h>

int main()
{
    int n = 100;
    int sum = 0;
    int num_threads = 1; // Number of threads to use

// Parallel region with a specified number of threads
#pragma omp parallel for num_threads(num_threads) reduction(+ : sum)
    for (int i = 0; i < n; i++)
    {
        sum += i;
    }

    printf("Sum: %d\n", sum);

    return 0;
}

#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    int i;
    int n = 10;

    // Parallel region with a shared variable
    #pragma omp parallel for shared(sum)
    for (i = 0; i < n; i++) {
        // Each thread adds its index to the shared variable sum
        sum += i;
    }

    // Print the final sum
    printf("Sum: %d\n", sum);

    return 0;
}
// each compiler may have a different output

// to fix the issue, we can use the reduction clause



#include <omp.h>
#include <stdio.h>

int main() {
    int n = 100;
    int sum = 0;
    int status;

    // Parallel region will execute if n is greater than 50
    #pragma omp parallel for if(n > 50) reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += i;
        status = omp_in_parallel();
        printf("status = %d\n", status);
    }

    printf("Sum: %d\n", sum);

    return 0;
}

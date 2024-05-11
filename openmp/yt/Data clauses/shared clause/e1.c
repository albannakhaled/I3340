#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 10; // This is a shared variable

    #pragma omp parallel shared(sum)
    {
    #pragma omp parallel for
    for (int i = 0; i < 100; i++) {
        sum += i;
    }
    sum += omp_get_thread_num();
    printf("Sum = %d\n", sum);
    }
    printf("Sum outside = %d\n", sum);
    return 0;
}
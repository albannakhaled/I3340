#include <omp.h>
#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;

    #pragma omp parallel for firstprivate(x) shared(y)
    for (int i = 0; i < 4; i++) {
        x += i;  // Each thread has its own copy of x
        y += i;  // All threads share the same y
        printf("Thread %d: x = %d, y = %d\n", omp_get_thread_num(), x, y);
    }

    printf("After parallel region: x = %d, y = %d\n", x, y);

    return 0;
}
#include <omp.h>
#include <stdio.h>

int main() {
    int i, n = 100;
    int sum = 0;

    #pragma omp parallel for reduction(+:sum) // 2iza mnshil l reduction bisir 3ndi data race , ==> wrong answer
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum: %d\n", sum);
    
    return 0;
}

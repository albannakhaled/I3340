#include <omp.h>
#include <stdio.h>

#define ARRAY_SIZE 100

int main() {
    int i;
    int sum = 0;
    int arr[ARRAY_SIZE];

    // Initialize array
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }
    printf("%d\n\n",arr[99]);

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);
    
    return 0;
}

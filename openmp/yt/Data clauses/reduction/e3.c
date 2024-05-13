#include <omp.h>
#include <stdio.h>

#define ARRAY_SIZE 100

int main() {
    int i;
    int max_value = 0;
    int arr[ARRAY_SIZE];

    // Initialize array
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }

    #pragma omp parallel for reduction(max:max_value)
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    printf("Max Value: %d\n", max_value);
    
    return 0;
}

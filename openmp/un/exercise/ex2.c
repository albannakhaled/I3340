/*
Write a C program that count the number of occurrence of a number
v in a table. Parallelize that program with OpenMP.
• What do you observe when the program is executed several times?

*/

#include <omp.h>
#include <stdio.h>

#define SIZE 1000

int countOccurrences(int arr[], int n, int v) {
    int count = 0;
    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[SIZE];
    int v = 5; // Number to search for
    int occurrences;

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i % 10; // Fill array with numbers from 0 to 9 repetitively
    }

  
    occurrences = countOccurrences(arr, SIZE, v);

    printf("Number of occurrences of %d: %d\n", v, occurrences);

    return 0;
}
